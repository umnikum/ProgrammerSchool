#include <iostream>
#include <string>
#include "UI.h"

int main() {
	UI ui;
	ui.execute_command({"load", "fruits_in.basket"});
	int code;
	std::string line;
	do{
		getline(std::cin, line);
		code = ui.execute_command(split(line));
		if(code < 0){
			UI::error(code);
			code = 1;
		}
	}while(code>0);
	return 0;
}
