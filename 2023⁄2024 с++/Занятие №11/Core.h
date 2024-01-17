#ifndef CORE_H_
#define CORE_H_

#include <initializer_list>
#include <cmath>
#include <map>
#include <string>
#include <sstream>

inline static constexpr char DELIMITER = '/';

class Coordinates{
public:
	int x, y;
	Coordinates(const int &x=0, const int &y=0):x(x),y(y){}
	Coordinates(const std::initializer_list<int> &values):x{*(values.begin())}, y{*(values.begin()+1)}{}
	Coordinates& operator=(const Coordinates &coor){
		x = coor.x; y = coor.y;
		return *this;
	}
	Coordinates operator+(const Coordinates &coor)const{
		return {x + coor.x, y + coor.y};}
	Coordinates operator-(const Coordinates &coor)const{
		return {x - coor.x, y - coor.y};}
	std::string str()const{
		std::stringstream ss;
		ss << "(" << x << ", " << y << ")";
		return ss.str();
	}
	friend Coordinates operator-(const Coordinates &coor){
		return Coordinates{-coor.x, -coor.y};}
	friend double distance(const Coordinates &a, const Coordinates &b){
		int dx{a.x-b.x}, dy{a.y-b.y};
		return std::sqrt(dx*dx+dy*dy);
	}
	friend bool operator==(const Coordinates &a, const Coordinates &b){
		return a.x==b.x and a.y==b.y;}
};

class Config{
public:
	std::map<std::string, std::map<std::string, std::string>> units;
	Config(const std::string &file_name="config.ini"):units{}{
		std::ifstream ifs{file_name};
		std::string line;
		getline(ifs, line);
		do{
			std::string unit_name = line.substr(line.find(":")+1, line.rfind(":")-1);
			std::map<std::string, std::string> unit{};
			do{
				getline(ifs, line);
				if(line.empty()) continue;
				if(line.front()!=':'){
					size_t equal_sign_position = line.find("=");
					std::string key = line.substr(0, equal_sign_position),
								value = line.substr(equal_sign_position+1);
					unit[key] = value;
				}else break;
			}while(!ifs.eof());
			units[unit_name] = unit;
		}while(!ifs.eof());
		ifs.close();
	}
};

class Sprite{
public:
	std::vector<std::string> lines;
	Sprite(const std::string &file_name){
		std::ifstream ifs(file_name);
		do{
			std::string line;
			getline(ifs, line);
			lines.push_back(line);
		}while(!ifs.eof());
	}
};

#endif /* CORE_H_ */
