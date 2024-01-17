#ifndef BASKET_H_
#define BASKET_H_

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class Fruit{
protected:
	std::string quality, name;
public:
	Fruit(const std::string &quality="", const std::string &name="nothing"):
		quality(quality), name(name){}
	bool is(const std::string &fruit_name)const{
		return name.compare(fruit_name)==0;}
	std::string str()const{
		std::stringstream ss;
		ss << quality << " " << name;
		return ss.str();
	}
	friend bool operator==(const Fruit &a, const Fruit &b){
		return a.quality.compare(b.quality)==0 and a.name.compare(b.name)==0;}
};

class Basket{
protected:
	std::vector<Fruit> containment;
public:
	virtual ~Basket(){}
	void put(const Fruit &fruit){
		containment.push_back(fruit);}
	std::vector<Fruit> look_inside()const{return containment;}
	std::vector<Fruit> look_for(const std::string &name)const{
		std::vector<Fruit> fruits;
		for(auto fruit:containment)
			if(fruit.is(name))
				fruits.push_back(fruit);
		return fruits;
	}
	Fruit take(const std::string &name){
		Fruit fruit;
		for(size_t i=0; i<containment.size(); ++i)
			if(containment[i].is(name)){
				fruit = containment[i];
				containment.erase(std::next(containment.begin(), i));
				break;
			}
		return fruit;
	}
	virtual std::vector<Fruit> take_all(const std::string &name){
		std::vector<Fruit> fruits;
		size_t i=0;
		while(i<containment.size()){
			if(containment[i].is(name)){
				fruits.push_back(containment[i]);
				containment.erase(std::next(containment.begin(), i));
			}else ++i;
		}
		return fruits;
	}
	std::vector<Fruit> take_all(){
		std::vector<Fruit> fruits(containment);
		containment.clear();
		return fruits;
	}
};

class FilterBasket : public Basket{
public:
	std::vector<Fruit> filter_all(const std::string &name){
		std::vector<Fruit> fruits;
		size_t i=0;
		while(i<containment.size()){
			if(!containment[i].is(name)){
				fruits.push_back(containment[i]);
				containment.erase(std::next(containment.begin(), i));
			}else ++i;
		}
		return fruits;
	}
};

class HiddenFilterBasket : public Basket{
public:
	using Basket::take_all;
	std::vector<Fruit> take_all(const std::string &name)override{
		std::vector<Fruit> fruits;
		size_t i=0;
		while(i<containment.size()){
			if(!containment[i].is(name)){
				fruits.push_back(containment[i]);
				containment.erase(std::next(containment.begin(), i));
			}else ++i;
		}
		return fruits;
	}
};

#endif /* BASKET_H_ */
