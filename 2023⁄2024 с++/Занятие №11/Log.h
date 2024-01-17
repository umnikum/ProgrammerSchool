#ifndef LOG_H_
#define LOG_H_

#include <iostream>
#include <string>
#include <sstream>
#include <chrono>
#include <fstream>
#include <iomanip>
#include "Core.h"

class Log{
protected:
	std::ofstream ofs{};
public:
	Log(){
		std::stringstream ss;
		auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
		ss << "Log" << DELIMITER << "Battle:" << std::put_time(std::localtime(&now), "%T_%F.log") << std::flush;
		ofs.open(ss.str());
	}
	void write(const std::string &message){
		ofs << message << "\n";
		ofs.flush();
	}
};



#endif /* LOG_H_ */
