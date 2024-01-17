#include <iostream>

#include "UI.h"

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


int main() {
	std::string line;
	std::vector<std::string> args;
	UI ui;
	do{
		getline(std::cin, line);
		args = split(line);
	}while(ui.execute_command(args) > 0);
	return 0;
}
