#ifndef BALLANCER_H_
#define BALLANCER_H_

#include <iostream>
#include <vector>
#include "Character.h"

class Ballancer{
protected:
	std::vector<Character> team;
public:
	int add_character(const Character &character){
		team.push_back(character);
		return get_general_score(character);
	}
	int score()const{
		int score{0};
		for(auto member:team)
			score+=get_general_score(member);
		return score;
	}
	void reset(){
		team.clear();}
private:
	int get_general_score(const Character &character)const{
		return get_dps_score(character)*get_survivability_score(character) + 2*get_attr_score(character);
	}
	int get_attr_score(const Character &character)const{
		int score{0};
		for(unsigned int attr_index=Attributes::STRENGTH; attr_index<=Attributes::PERCEPTION; ++attr_index)
			score+=character.attr[attr_index];
		return score;
	}
	int get_dps_score(const Character &character)const{
		return (character.attr[Attributes::STRENGTH]+1)*(12/(5-character.attr[Attributes::AGILITY]));}
	int get_survivability_score(const Character &character)const{
		return character.attr[Attributes::VITALITY]*2;
	}
};



#endif /* BALLANCER_H_ */
