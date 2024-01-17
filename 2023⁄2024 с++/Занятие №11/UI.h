#ifndef UI_H_
#define UI_H_

#include <fstream>
#include <string>
#include <vector>
#include "Engine.h"

class UI{
public:
	int execute_command(std::vector<std::string> &args){
		std::string command = args[0];
		args.erase(args.begin());
		if(command.compare("exit") == 0){
			return 0;
		}else if(command.compare("start") == 0){
			Engine engine{};
			engine.start();
			return 1;
		}else if(command.compare("set_team") == 0){
			return set_team(args);
		}
		return -1;
	}
private:
	int set_team(std::vector<std::string> &args)const{
		std::string file_name = args[0];
		args.erase(args.begin());
		std::ofstream ofs{file_name};
		for(auto arg:args)
			ofs << arg << "\n";
		return 2;
	}
};



#endif /* UI_H_ */
