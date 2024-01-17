#ifndef STRATEGY_H_
#define STRATEGY_H_

#include <vector>
#include <random>
#include "Core.h"
#include "Character.h"
#include "Board.h"
#include "GameState.h"

class Strategy{
protected:
	GameState &game_state;
public:
	Strategy(GameState &game_state):game_state{game_state}{}

	virtual Coordinates choose_move()const{
		std::vector<Character> enemies = game_state.look("enemies");
		Coordinates direction;
		if(enemies.size() == 0){
			direction = patroll();
		}else{
			direction = persue(enemies[0].coordinates);
			walk_around(direction);
		}
		return game_state.perspective().coordinates+direction;
	}

	virtual ~Strategy() = default;
protected:
	virtual Coordinates patroll()const{
		Coordinates direction = game_state.perspective().direction;
		walk_around(direction);
		return direction;
	}
	virtual Coordinates persue(const Coordinates &target)const{
		return game_state.in_direction(target);}

	void walk_around(Coordinates &direction)const{
		if(!(direction==Coordinates{}))
			while(!assert_possible_position(direction)){
				sub_rotate_clockwise(direction);
			}
	}
	bool assert_possible_position(const Coordinates &direction)const{
		const Character &self = game_state.perspective();
		Coordinates coor = self.coordinates+direction;
		if(!game_state.board.assert_coordinates(coor)){
			return false;
		}
		Containment cont{game_state.check(coor)};
		if(cont == EMPTY or cont == ENEMIE)
			return true;
		else return false;
	}
	void rotate_clockwise(Coordinates &direction)const{
		Coordinates memory(direction);
		switch(memory.x){
		case -1:
			direction.y = -1;
			break;
		case 1:
			direction.y = 1;
			break;
		default: break;
		}
		switch(memory.y){
		case -1:
			direction.x = 1;
			break;
		case 1:
			direction.x = -1;
			break;
		default: break;
		}
	}
	void rotate_counterclockwise(Coordinates &direction)const{
		Coordinates memory(direction);
		switch(memory.x){
		case -1:
			direction.y = 1;
			break;
		case 1:
			direction.y = -1;
			break;
		default: break;
		}
		switch(memory.y){
		case -1:
			direction.x = -1;
			break;
		case 1:
			direction.x = 1;
			break;
		default: break;
		}
	}
	void sub_rotate_clockwise(Coordinates &direction)const{
		Coordinates memory(direction);
		rotate_clockwise(memory);
		direction = direction+memory;
		if(direction.x == 2)
			direction.x = 1;
		else if(direction.x == -2)
			direction.x = -1;
		if(direction.y == 2)
			direction.y = 1;
		else if(direction.y == -2)
			direction.y = -1;
	}
	void sub_rotate_counterclockwise(Coordinates &direction)const{
		Coordinates memory(direction);
		rotate_counterclockwise(memory);
		direction = direction+memory;
		if(direction.x == 2)
			direction.x = 1;
		else if(direction.x == -2)
			direction.x = -1;
		if(direction.y == 2)
			direction.y = 1;
		else if(direction.y == -2)
			direction.y = -1;
	}
};

class ZombieStrategy : public Strategy{
public:
	using Strategy::Strategy;
protected:
	inline static constexpr double step_left=0.1, step_right=0.9;
	Coordinates patroll()const override{
		Coordinates direction = game_state.perspective().direction;
		std::mt19937 gen{std::random_device{}()};
		std::uniform_real_distribution<double> distr{0.0, 1.0};
		double random_value = distr(gen);
		if(random_value <= step_left){
			sub_rotate_counterclockwise(direction);
			walk_around(direction);
		}else if(random_value >= step_right){
			sub_rotate_clockwise(direction);
			walk_around(direction);
		}else direction = Coordinates{};
		return direction;
	}
};

class GoblinStrategy : public Strategy{
public:
	using Strategy::Strategy;
protected:
	Coordinates patroll()const override{
		std::vector<Character> allies = game_state.look("allies");
		Coordinates direction = (allies.size()==0)? game_state.perspective().direction : allies[0].direction;
		walk_around(direction);
		return direction;
	}
	Coordinates persue(const Coordinates &target)const override{
		const Character &self{game_state.perspective()};
		std::vector<Character> characters = game_state.look("all");
		size_t allies{0}, enemies{0};
		for(auto character:characters)
			if(character.fraction == self.fraction){
				++allies;
			}else ++enemies;
		return (allies<enemies)? -game_state.in_direction(target) : game_state.in_direction(target);
	}
};

class GolemStrategy : public Strategy{
protected:
	size_t max_y, min_y;
public:
	GolemStrategy(GameState &game_state):Strategy(game_state),
		max_y{static_cast<size_t>(game_state.board.get_width()*0.7)},
		min_y{static_cast<size_t>(game_state.board.get_width()*0.3)}{}
protected:
	Coordinates patroll()const override{
		const Character &character{game_state.perspective()};
		const Coordinates &coor{character.coordinates}, &char_direction{character.direction};
		Coordinates direction{char_direction.x, (char_direction.y == 0)? -1 : char_direction.y};
		size_t possible_y{static_cast<size_t>(coor.y+direction.y)};
		if(possible_y < min_y or possible_y > max_y)
			direction = -direction;
		walk_around(direction);
		return direction;
	}
	Coordinates persue(const Coordinates &target)const override{
		Coordinates direction = game_state.in_direction(target),
					move = game_state.perspective().coordinates + direction;
		Containment cont=game_state.check(move);
		if(cont == ENEMIE)
			return direction;
		else return Coordinates{};
	}
};

#endif /* STRATEGY_H_ */
