#ifndef GAMESTATE_H_
#define GAMESTATE_H_


#include <cassert>
#include <cmath>
#include <string>
#include <map>
#include "Board.h"
#include "Character.h"

enum Containment{
	EMPTY,
	GRAVE,
	ENEMIE,
	ALLIE
};

class GameState{
public:
	Board board;
	std::map<size_t, Character> characters;
	size_t game_time{0}, perspective_id{0};
	GameState(){
		Config config{};
		board = Board{std::stoull(config.units["size"]["width"]),
					  std::stoull(config.units["size"]["length"])};
	}
	void reset(){
		std::vector<size_t> ids;
		for(auto pair:characters)
			ids.push_back(pair.first);
		for(auto id:ids)
			remove_character(id);
		game_time=0;
		perspective_id=0;
	}
	void spawn_character(const Coordinates &coor, const Character &character, const char &fraction='a'){
		assert(board.assert_coordinates(coor));
		characters.emplace(character.id, character);
		Character &back = characters[character.id];
		back.fraction = fraction;
		back.coordinates = coor;
		back.direction = (fraction == 'a')? Coordinates{1,0} : Coordinates{-1,0};
		board[coor.y][coor.x].place_character(character.id);
	}
	void remove_character(const size_t &id){
		Coordinates &coor = characters[id].coordinates;
		board[coor.y][coor.x].remove_character();
		characters.erase(id);
	}
	void move_character(const Coordinates &coor, const size_t &character_id){
		assert(board.assert_coordinates(coor));
		Coordinates &old_coor = characters[character_id].coordinates;
		board[old_coor.y][old_coor.x].remove_character();
		old_coor = coor;
		board[old_coor.y][old_coor.x].place_character(character_id);
	}
	void next_turn(){++game_time;}
	const Character& perspective()const{
		return characters.at(perspective_id);}

	std::map<char, size_t> count_survivors()const{
		std::map<char, size_t> survivors;
		for(auto pair:characters){
			char fraction=pair.second.fraction;
			if(survivors.count(fraction) == 0){
				survivors[fraction] = (pair.second.state == DEAD)? 0 : 1;
			}else {
				if(pair.second.state != DEAD)
					++survivors[fraction];
			}
		}
		return survivors;
	}

	bool finish_condition()const{
		std::map<char, size_t> survivors = count_survivors();
		bool alive_team = false;
		for(auto pair:survivors){
			if(pair.second != 0){
				if(alive_team){
					return false;
				}else alive_team = true;
			}
		}
		return true;
	}


	void set_percpective(const size_t &character_id){
		assert(characters.count(character_id) > 0);
		perspective_id = character_id;
	}
	bool is_reacting()const{
		return game_time % (5-perspective().attr[Attributes::AGILITY]) == 0;}

	Containment check(const Coordinates &coor)const{
		const Cell &cell{board[coor.y][coor.x]};
		if(!cell.has_character){
			return EMPTY;
		}else{
			const Character &character{characters.at(cell.get_character_id())};
			if(character.state == DEAD){
				return GRAVE;
			}else{
				if(character.fraction == perspective().fraction){
					return ALLIE;
				}else return ENEMIE;
			}
		}
	}

	const Character& search(const std::string &key="all")const{
		const Character &self = perspective();
		int radius = self.attr[Attributes::PERCEPTION]+1;
		const Coordinates &coor = self.coordinates;
		Coordinates point_of_interest = coor;
		for(point_of_interest.y=coor.y-radius; point_of_interest.y<=coor.y+radius; ++point_of_interest.y){
			for(point_of_interest.x=coor.x-radius; point_of_interest.x<=coor.x+radius; ++point_of_interest.x){
				double dist = distance(coor, point_of_interest);
				if(dist <= radius and dist != 0.0 and board.assert_coordinates(point_of_interest)){
					Containment cont{check(point_of_interest)};
					switch(cont){
					case EMPTY:
					case GRAVE:
						break;
					case ENEMIE:
						if(key.compare("all")==0 or key.compare("enemies")==0)
							return characters.at(board[point_of_interest.y][point_of_interest.x].get_character_id());
						break;
					case ALLIE:
						if(key.compare("all")==0 or key.compare("allies")==0)
							return characters.at(board[point_of_interest.y][point_of_interest.x].get_character_id());
						break;
					}
				}
			}
		}
		return self;
	}
	std::vector<Character> look(const std::string &key="all")const{
		const Character &self = perspective();
		std::vector<size_t> result_ids{};
		int radius = self.attr[Attributes::PERCEPTION]+1;
		const Coordinates &coor = self.coordinates;
		Coordinates point_of_interest = coor;
		for(point_of_interest.y=coor.y-radius; point_of_interest.y<=coor.y+radius; ++point_of_interest.y){
			for(point_of_interest.x=coor.x-radius; point_of_interest.x<=coor.x+radius; ++point_of_interest.x){
				double dist = distance(coor, point_of_interest);
				if(dist <= radius and dist != 0.0 and board.assert_coordinates(point_of_interest)){
					Containment cont{check(point_of_interest)};
					switch(cont){
					case EMPTY:
					case GRAVE:
						break;
					case ENEMIE:
						if(key.compare("all")==0 or key.compare("enemies")==0)
							result_ids.push_back(board[point_of_interest.y][point_of_interest.x].get_character_id());
						break;
					case ALLIE:
						if(key.compare("all")==0 or key.compare("allies")==0)
							result_ids.push_back(board[point_of_interest.y][point_of_interest.x].get_character_id());
						break;
					}
				}
			}
		}
		for(size_t from=1; from<result_ids.size(); ++from)
			for(size_t i=from; i>0; --i)
				if(distance(self.coordinates, characters.at(result_ids[i]).coordinates)
					< distance(self.coordinates, characters.at(result_ids[i-1]).coordinates))
					std::swap(result_ids[i], result_ids[i-1]);
		std::vector<Character> result;
		for(auto id:result_ids)
			result.push_back(characters.at(id));
		return result;
	}

	Coordinates in_direction(const Coordinates &coor)const{
		double accuracy = 0.3;
		Coordinates coordinates = perspective().coordinates, result{};
		int dx{coor.x-coordinates.x}, dy{coor.y-coordinates.y};
		double dr = distance(coor, coordinates);
		if(dx/dr < -accuracy)
			result.x--;
		else if(dx/dr > accuracy)
			result.x++;
		if(dy/dr < -accuracy)
			result.y--;
		else if(dy/dr > accuracy)
			result.y++;
		return result;
	}
	void print()const{
		const Sprite &empty_sprite{board.empty_sprite},
				&grave_sprite{board.grave_sprite};
		for(size_t x=0; x<board.get_length()*empty_sprite.lines[0].size()+2; ++x){
			std::cout << '-';}
		std::cout << "\n";
		for(size_t y=0; y<board.get_width(); ++y){
			for(size_t line_index=0; line_index<empty_sprite.lines.size(); ++line_index){
				std::cout << "|";
				for(size_t x=0; x<board.get_length(); ++x){
					Containment cont{check(Coordinates{static_cast<int>(x), static_cast<int>(y)})};
					switch(cont){
					case GRAVE:
						std::cout << grave_sprite.lines[line_index];
						break;
					case ENEMIE:
					case ALLIE:
						std::cout << characters.at(board[y][x].get_character_id()).sprite.lines.at(line_index);
						break;
					case EMPTY:
					default:
						std::cout << empty_sprite.lines[line_index];
					}
				}
				std::cout << "|\n";
			}
		}
		for(size_t x=0; x<board.get_length()*empty_sprite.lines[0].size()+2; ++x){
			std::cout << '-';}
		std::cout << "\n";
	}
};


#endif /* GAMESTATE_H_ */
