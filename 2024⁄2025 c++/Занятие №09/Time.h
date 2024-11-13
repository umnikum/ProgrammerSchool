#ifndef TIME_H_
#define TIME_H_

#include <string>

class Time{
public:
	static constexpr int HOURS_IN_DAY = 24, MINUTES_IN_HOUR = 60, SECONDS_INT_MINUTE = 60;
	int seconds, minutes, hours;
	
	Time(int seconds);
	Time(int hours, int minutes, int seconds);
	
	Time operator+(const Time &time)const;
	Time operator-(const Time &time)const;

	friend std::string to_string(const Time &time);
};

#endif /* TIME_H_ */
