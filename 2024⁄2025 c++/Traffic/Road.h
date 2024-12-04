#ifndef ROAD_H_
#define ROAD_H_

#include <sstream>
#include <string>

class Road{
private:
	unsigned int A, B;
	double len;
public:
	Road();
	Road(const unsigned int &A, const unsigned int &B, const double &length);
	unsigned int from()const;
	unsigned int to()const;
	double length()const;
	friend std::string to_string(const Road &road);
};


#endif /* ROAD_H_ */
