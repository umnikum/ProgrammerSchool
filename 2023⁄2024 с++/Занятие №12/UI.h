#ifndef UI_H_
#define UI_H_

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include "Basket.h"

std::vector<std::string> split(const std::string &line){
    std::vector<std::string> args;
    auto previousIt = line.begin();
    auto nextIt = previousIt;
    do{
        nextIt = std::find(previousIt, line.end(), ' ');
        std::string arg = line.substr(previousIt-line.begin(), nextIt-previousIt);
        if(!arg.empty())
            args.push_back(arg);
        previousIt = nextIt+1;
    }while(nextIt != line.end());
    return args;
}

class UI{
protected:
	HiddenFilterBasket basket;
public:
	int execute_command(std::vector<std::string> args){
		std::string command = args[0];
		args.erase(args.begin());
		if(command.compare("put")==0){
			return put_fruit(args);
		}else if(command.compare("look")==0){
			return look(args);
		}else if(command.compare("take")==0){
			return take(args);
		}else if(command.compare("store")==0){
			return store(args);
		}else if(command.compare("load")==0){
			return load(args);
		}else if(command.compare("exit")==0){
			return 0;
		}
		return -1;
	}
	static void error(const int &code){
		switch(code){
		case -2:
		case -5:
		case -6:
			std::cout << "Insufficient arguments!\n";
			break;
		case -4:
			std::cout << "Fruit not found!\n";
			break;
		case -1:
			std::cout << "Unknown command!\n";
			break;
		default:
			std::cout << "No error found!\n";
		}
	}
private:
	int put_fruit(std::vector<std::string> &args){
		if(args.size() < 2){
			return -2;
		}else{
			basket.put({args[0], args[1]});
			return 2;
		}
	}
	int look(std::vector<std::string> &args){
		if(args.size() > 0){
			for(auto fruit:basket.look_for(args[0]))
				std::cout << fruit.str() << "\n";
		}else{
			for(auto fruit:basket.look_inside())
				std::cout << fruit.str() << "\n";
		}
		return 3;
	}
	int take(std::vector<std::string> &args){
		if(args.size() > 0){
			const std::string &name = args[0];
			if(name.compare("all")==0 and args.size()>1){
				for(auto fruit:basket.take_all(args[1]))
					std::cout << fruit.str() << "\n";
			}else{
				auto fruit = basket.take(name);
				if(fruit.is("nothing")){
					return -4;
				}else{
					std::cout << fruit.str() << "\n";
				}
			}
			return 4;
		}else{
			return -4;
		}
	}
	int store(std::vector<std::string> &args){
		if(args.size() > 0){
			std::ofstream ofs{args[0]};
			for(auto fruit:basket.take_all())
				ofs << fruit.str() << "\n";
			ofs.close();
			return 5;
		}else{
			return -5;
		}
	}
	int load(std::vector<std::string> &args){
		if(args.size() > 0){
			std::ifstream ifs{args[0]};
			std::string quality, name;
			do{
				ifs >> quality >> name;
				basket.put({quality, name});
			}while(!ifs.eof());
			ifs.close();
			return 5;
		}else{
			return -6;
		}
	}
};



#endif /* UI_H_ */
