#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum Side{
	WHITE,
	BLACK
};

class Strategy{
public:
	virtual vector<string> operator()(const string& initial_position)const{
		return vector<string>{initial_position};
	}
};

class ForwardStrategy: public Strategy{
public:
	Side side;
	ForwardStrategy(const Side& side):side{side}{}
	
	
	vector<string> operator()(const string& initial_position)const override{
		string result{initial_position};
		result[1] += ((side==WHITE)?1:-1);
		return vector<string>{result};
	}
};

class Chesspiece{
public:
	Side side{WHITE};
	string position;
	Strategy* movement = nullptr;
	
	Chesspiece(const string& position, Strategy* movement):position{position}, movement{movement}{}
	
	void set_movement(Strategy* new_movement){movement = new_movement;}
	vector<string> get_moves()const{return (*movement)(position);}
};

int main(){
	Strategy strat;
	ForwardStrategy fstrat{WHITE};
	Chesspiece pawn{"A2", &strat};
	for(auto move:pawn.get_moves())
		cout << move << "\n";
	pawn.set_movement(&fstrat);
	for(auto move:pawn.get_moves())
		cout << move << "\n";
	return 0;
}
