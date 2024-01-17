#ifndef ENGINE_H_
#define ENGINE_H_

#include <cassert>
#include <algorithm>
#include <map>
#include <chrono>
#include <thread>
#include <fstream>
#include "Board.h"
#include "Character.h"
#include "GameState.h"
#include "Strategy.h"
#include "Log.h"
#include "Ballancer.h"

class Engine{
protected:
	Log log{};
	GameState game_state;
	Strategy default_strategy{game_state};
	ZombieStrategy zombie_strategy{game_state};
	GoblinStrategy goblin_strategy{game_state};
	GolemStrategy golem_strategy{game_state};
public:
	Engine():game_state{}{}

	void start(){
		log.write("Battle started:");
		size_t tick = 100;
		spawn_teams();
		game_state.print();

		do{
			for(auto character_pair:game_state.characters){
				game_state.set_percpective(character_pair.first);
				if(game_state.is_reacting() and game_state.perspective().state == NORMAL){
					make_move(choose_strategy().choose_move());
				}
			}
			game_state.print();
			game_state.next_turn();
			std::this_thread::sleep_for(std::chrono::milliseconds{tick});
		}while(!game_state.finish_condition());

		std::map<char, size_t> survivors = game_state.count_survivors();
		std::stringstream ss;
		ss << "Battle finished with results:\n";
		for(auto pair:survivors){
			ss << "team:" << pair.first << " - " << pair.second << " survived";
			if(pair.second > 0)
				ss << " winner!";
			ss << std::endl;
		}
		log.write(ss.str());
		std::cout << ss.str();
		game_state.reset();
	}
protected:
	std::vector<Coordinates> get_formation(const size_t &size=1, const char &fraction = 'a'){
		std::vector<Coordinates> formation(size);
		int width = game_state.board.get_width(), length = game_state.board.get_length(), retreat_reach = length/10,
				allie_distance = (width>static_cast<int>(size)*3)? 2 : 1;
		switch(fraction){
		case 'a':
			switch(size){
			case 1:
				formation[0] = {retreat_reach, width/2};
				break;
			case 2:
				formation[0] = {retreat_reach, (width+allie_distance)/2};
				formation[1] = {retreat_reach, (width-allie_distance)/2};
				break;
			case 3:
				formation[0] = {retreat_reach, width/2+allie_distance};
				formation[1] = {retreat_reach, width/2-allie_distance};
				formation[2] = {retreat_reach+1, width/2};
				break;
			case 4:
			default:
				formation[0] = {retreat_reach, (width+allie_distance)/2+allie_distance};
				formation[1] = {retreat_reach, (width-allie_distance)/2-allie_distance};
				formation[2] = {retreat_reach+1, (width+allie_distance)/2};
				formation[3] = {retreat_reach+1, (width-allie_distance)/2};
			}
			break;
		case 'b':
		default:
			switch(size){
			case 1:
				formation[0] = {length-retreat_reach-1, width/2};
				break;
			case 2:
				formation[0] = {length-retreat_reach-1, (width+allie_distance)/2};
				formation[1] = {length-retreat_reach-1, (width-allie_distance)/2};
				break;
			case 3:
				formation[0] = {length-retreat_reach-1, width/2+allie_distance};
				formation[1] = {length-retreat_reach-1, width/2-allie_distance};
				formation[2] = {length-retreat_reach-2, width/2};
				break;
			case 4:
			default:
				formation[0] = {length-retreat_reach-1, (width+allie_distance)/2+allie_distance};
				formation[1] = {length-retreat_reach-1, (width-allie_distance)/2-allie_distance};
				formation[2] = {length-retreat_reach-2, (width+allie_distance)/2};
				formation[3] = {length-retreat_reach-2, (width-allie_distance)/2};
			}
		}
		return formation;
	}
	void spawn_teams(){
		constexpr int max_score = 520;
		Ballancer ballancer;
		std::ifstream ifs{"A.team"};
		std::vector<std::string> team;
		do{
			std::string line;
			getline(ifs, line);
			team.push_back(line);
		}while(!ifs.eof());
		std::vector<Coordinates> formation = get_formation(team.size(), 'a');
		for(size_t i=0; i<team.size(); ++i){
			Character character = Character::load(team[i]);
			game_state.spawn_character(formation[i], character, 'a');
			ballancer.add_character(character);
		}
		assert(ballancer.score() < max_score and "Team A is OP");
		team.clear(); formation.clear(); ifs.close(); ballancer.reset();
		ifs.open("B.team");
		do{
			std::string line;
			getline(ifs, line);
			team.push_back(line);
		}while(!ifs.eof());
		formation = get_formation(team.size(), 'b');
		for(size_t i=0; i<team.size(); ++i){
			Character character = Character::load(team[i]);
			game_state.spawn_character(formation[i], character, 'b');
			ballancer.add_character(character);
		}
		assert(ballancer.score() < max_score and "Team B is OP");
		ifs.close();
	}
	Strategy& choose_strategy(){
		const Character& character{game_state.perspective()};
		if(character.name.compare("Zombie")==0){
			return zombie_strategy;
		}else if(character.name.compare("Goblin")==0){
			return goblin_strategy;
		}else if(character.name.compare("Golem")==0){
			return golem_strategy;
		}else return default_strategy;
	}
	void make_move(const Coordinates &coor){
		Character &character = game_state.characters[game_state.perspective_id];
		Containment cont = game_state.check(coor);
		if(cont == EMPTY){
			character.direction = game_state.in_direction(coor);
			game_state.move_character(coor, character.id);
		}else if(cont == ENEMIE){
			std::stringstream ss;
			ss << "Tick:" << game_state.game_time << "\t" << character.str()  << "\t" << character.coordinates.str();
			character.direction = game_state.in_direction(coor);
			Character &target = game_state.characters[game_state.board[coor.y][coor.x].get_character_id()];
			ss << " attacking: " << target.str() << " health: " << target.health << "->";
			damage(target);
			if(target.attr[Attributes::STRENGTH] < character.attr[Attributes::STRENGTH]){
				Coordinates displacement=target.coordinates+character.direction;
				if(game_state.board.assert_coordinates(displacement) and game_state.check(displacement) == EMPTY){
					game_state.move_character(displacement, target.id);
					game_state.move_character(coor, character.id);
					ss << target.health << " displaced!";
				}else{
					damage(target);
					ss << target.health << " cornered!";
				}
			}else ss << target.health;
			if(target.health == 0){
				target.state = DEAD;
				ss << " DEAD";
			}
			log.write(ss.str());
		}
	}
	void damage(Character &character){
		unsigned int &health = character.health,
				damage = game_state.perspective().attr[Attributes::STRENGTH]+1;
		health = (health > damage)? health-damage : 0;
	}
};

#endif /* ENGINE_H_ */
