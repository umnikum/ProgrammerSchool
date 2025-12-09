#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <map>

class Passanger{
public:
	long sit_val, stay_val, start, finish;
	Passanger(const int& a=0, const int& b=0, const int& c=1, const int& d=2):sit_val{a}, stay_val{b}, start{c}, finish{d}{}
	
	bool inside(const int& stop)const{return stop>=start and stop<finish;}
	bool stays()const{return sit_val<=stay_val;}
};

class Bus{
public:
	std::multimap<int, Passanger> passangers{};
	int cur_stop=0;
	int sittings;
	long long fitness = 0l;
	
	Bus(const int& M):sittings{M}{}
	
	void add(const Passanger& psg){
		if(not psg.stays()){
			passangers.insert(std::pair<int, Passanger>{psg.stay_val - psg.sit_val, psg});
		}else fitness += psg.stay_val * (psg.finish - psg.start);
	}

	void move(const int& stop){
		long cur_sit = 0, interval = stop-cur_stop;
		for(auto p:passangers){
			if(p.second.inside(cur_stop)){
				if(cur_sit<sittings){
					++cur_sit;
					fitness += interval*p.second.sit_val;
				}else{
					fitness += interval*p.second.stay_val;
				}
			}
		}
		cur_stop = stop;
	}
};

int main(){
	int N, M, P, a, b, c, d;
	std::map<int, int> stops{};
	std::ifstream ifs{"input.txt"};
	ifs >> N >> M >> P;
	Bus bus{M};
	for(int i=0; i<N; ++i){
		ifs >> a >> b >> c >> d;
		stops.insert(std::pair<int, int>{c, 0});
		stops.insert(std::pair<int, int>{d, 0});
		bus.add(Passanger{a,b,c,d});
	}
	ifs.close();

	for(auto p:stops)
		bus.move(p.first);

	std::cout << bus.fitness;
	return 0;
}
