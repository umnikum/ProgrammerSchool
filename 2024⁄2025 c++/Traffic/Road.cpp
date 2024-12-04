#include <sstream>
#include <string>
#include <cassert>
#include "Road.h"

Road::Road():A{0},B{0},len{0.0}{}
Road::Road(const unsigned int &A,const unsigned int &B,const double &length):
			A{A}, B{B}, len{length}{assert(length >= 0.0);}

double Road::length()const{return len;}
unsigned int Road::from()const{return A;}
unsigned int Road::to()const{return B;}

std::string to_string(const Road &road){
	std::stringstream ss;
	ss << "Road: " << road.from() << " -(" << road.length() << ")-> "  << road.to();
	return ss.str();
}
