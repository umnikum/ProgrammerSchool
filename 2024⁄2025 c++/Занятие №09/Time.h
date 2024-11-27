#ifndef TIME_H_
#define TIME_H_

#include <string>
#include <sstream>

class Time{
private:
	void init(int total_seconds){
		if(total_seconds < 0){
			unsigned int day = HOURS_IN_DAY*MINUTES_IN_HOUR*SECONDS_IN_MINUTE;
			total_seconds = day - (-total_seconds) % day
		}
		seconds = total_seconds % SECONDS_IN_MINUTE;
		minutes = total_seconds / SECONDS_IN_MINUTE % MINUTES_IN_HOUR;
		hours =  total_seconds / (SECONDS_IN_MINUTE * MINUTES_IN_HOUR) % HOURS_IN_DAY;
	}
public:
	static constexpr unsigned int HOURS_IN_DAY = 24, MINUTES_IN_HOUR = 60, SECONDS_IN_MINUTE = 60;
	unsigned int hours, minutes, seconds;
	
	Time(int seconds){
		init(seconds);
	}
	Time(unsigned int hours, unsigned int minutes, unsigned int seconds):
		hours{hours}, minutes{minutes}, seconds{seconds}{
		if(hours >= HOURS_IN_DAY or minutes >= MINUTES_IN_HOUR or seconds >= SECONDS_IN_MINUTE)
			init(seconds + SECONDS_IN_MINUTE*minutes + SECONDS_IN_MINUTE*MINUTES_IN_HOUR*hours);
	}
	
	int to_seconds()const{
		return seconds + SECONDS_IN_MINUTE*minutes + SECONDS_IN_MINUTE*MINUTES_IN_HOUR*hours;
	}
	
	Time operator+(const Time &time)const{
		return Time{to_seconds() + time.to_seconds()};
	}
	Time operator-(const Time &time)const{
		return Time{to_seconds() - time.to_seconds()};
	}

	bool operator==(const Time &time)const{
		return hours==time.hours and minutes==time.minutes and seconds==time.seconds;
	}
	bool operator<(const Time &time)const{
		return to_seconds() < time.to_seconds();
	}
	bool operator<=(const Time &time)const{
		return to_seconds() <= time.to_seconds();
	}
	bool operator>(const Time &time)const{
		return to_seconds() > time.to_seconds();
	}
	bool operator>=(const Time &time)const{
		return to_seconds() >= time.to_seconds();
	}
	friend std::string to_string(const Time &time){
		std::stringstream ss;
		ss << time.hours << ":" << time.minutes << " : " << time.seconds;
		return ss.str();
	}
};

#endif /* TIME_H_ */
