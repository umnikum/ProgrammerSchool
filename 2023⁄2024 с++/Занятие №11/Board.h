#ifndef BOARD_H_
#define BOARD_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
#include "Core.h"

class Cell{
protected:
	Coordinates coor;
	size_t character_id{0};
public:
	bool has_character{false};
	Cell(const Coordinates &coor):coor(coor){}
	Cell(const std::initializer_list<int> &values={0,0}):coor(values){}
	Coordinates& get_coordinates(){return coor;}
	size_t get_character_id()const{return character_id;}
	size_t remove_character(){
		size_t memory{character_id};
		character_id = 0;
		has_character = false;
		return memory;
	}
	int place_character(const int &character_id){
		size_t memory{this->character_id};
		this->character_id = character_id;
		has_character = true;
		return memory;
	}
	~Cell() = default;
};

class Board{
protected:
	size_t length, width;
	std::vector<Cell> cells;
public:
	Sprite empty_sprite{get_file("Empty")}, grave_sprite{get_file("Grave")};
	Board(const size_t &width=0, const size_t &length=0):
		length{length}, width{width}, cells(length*width){
		for(size_t y=0; y<width; ++y)
			for(size_t x=0; x<length; ++x){
				Coordinates &coor = cells[y*length + x].get_coordinates();
				coor.x = x;	coor.y = y;
			}
	}
	std::vector<Cell>::iterator operator[](const size_t &index){
		assert(index < length);
		return std::next(cells.begin(), length*index);
	}
	std::vector<Cell>::const_iterator operator[](const size_t &index)const{
		assert(index < length);
		return std::next(cells.cbegin(), length*index);
	}
	size_t get_length()const{return length;}
	size_t get_width()const{return width;}
	bool assert_coordinates(const Coordinates &coor)const{
		return (static_cast<size_t>(coor.x) < length and static_cast<size_t>(coor.y) < width);}
private:
	std::string get_file(const std::string &name)const{
		std::stringstream ss;
		ss << "Sprites" << DELIMITER << name << ".sprite";
		return ss.str();
	}
};

#endif /* BOARD_H_ */
