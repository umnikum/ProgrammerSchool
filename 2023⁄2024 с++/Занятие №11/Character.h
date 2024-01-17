#ifndef CHARACTER_H_
#define CHARACTER_H_

#include <cassert>
#include <vector>
#include <initializer_list>
#include <string>
#include <sstream>
#include <fstream>
#include <functional>
#include "Core.h"

enum State{
	NORMAL,
	STUNNED,
	DEAD
};

class Attributes{
protected:
	std::vector<unsigned int> values;
public:
	inline static constexpr unsigned int STRENGTH=0, AGILITY=1, INTELIGENCE=2, VITALITY=3, PERCEPTION=4;
	Attributes(const std::initializer_list<unsigned int> &values={1, 1, 1, 1, 1}):values(values){
		for(auto value:values)
			assert(value < 5);
	}
	Attributes(const std::vector<unsigned int> &values):values(values){
		for(auto value:values)
			assert(value < 5);
	}
	Attributes(const Attributes &attr):values(attr.values){}
	unsigned int operator[](const unsigned int &index)const{return values.at(index);}
};

class Character{
protected:
	inline static size_t next_character_id = 0;
public:
	const Attributes attr;
	const Sprite sprite;

	size_t id{0};
	std::string name{};
	State state{NORMAL};
	Coordinates coordinates={}, direction={};
	unsigned int health;
	char fraction{'a'};

	Character():attr{}, sprite{get_file("Empty")},
			health{attr[Attributes::VITALITY]*2}{}
	Character(const Attributes &attr, const Sprite &sprite, const std::string &name):
			attr(attr), sprite(sprite),
			id{next_character_id}, name(name), health{attr[Attributes::VITALITY]*2}
			//damage{attr[Attributes::STRENGTH]+1},
			{++next_character_id;}
	std::string str()const{
		std::stringstream ss;
		ss << "#" << id << ":" << name << "[" << fraction << "]";
		return ss.str();
	}
	static Character load(const std::string &name){
		std::stringstream char_file, sprite_file;
		char_file << "Characters"<< DELIMITER << name << ".character";
		sprite_file << "Sprites" << DELIMITER << name << ".sprite";
		std::ifstream ifs{char_file.str()};
		std::vector<unsigned int> values;
		do{
			unsigned int value;
			ifs >> value;
			values.push_back(value);
		}while(!ifs.eof());
		ifs.close();
		return Character{Attributes(values), Sprite{sprite_file.str()}, name};
	}

	~Character() = default;
private:
	std::string get_file(const std::string &name)const{
		std::stringstream ss;
		ss << "Sprites" << DELIMITER << name << ".sprite";
		return ss.str();
	}
};

#endif /* CHARACTER_H_ */
