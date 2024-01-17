#include <iostream>
#include <fstream>
#include "Time.h"

/*
 * В файле дано расписание звонков. Если первый звонок на урок,
 * посчитать общую длинну перемен в минутах.
 */


//Структура это базовый сложный тип
struct Time_struct{
//Про это слово попозже!
public:
	//unsigned - беззнаковый тип, всегда больше 0
	unsigned int hours;
	unsigned int minutes;
	unsigned int seconds;
};//Заметим необходимость точки запятой после скобки!


//const - постоянное значение, не изменяемое внутри блока
//& - адрес переменной, без копирования информации
std::string print(const Time_struct &time){
	std::stringstream ss;
	//0, если меньше 10 часов
	if(time.hours < 10)
		ss << '0';
	ss << time.hours << ':';
	//0 если меньше 10 минут
	if(time.minutes < 10)
		ss << '0';
	ss << time.minutes;
	return ss.str();
}

using namespace std;

int main() {
	Time sum{0}, start, finish;
	unsigned int hours, minutes;

	ifstream is{"input.txt"};
	is >> hours >> minutes;
	start = {hours, minutes};
	do{
		is >> hours >> minutes;
		finish = {hours, minutes};
		if(!is.eof()){
			is >> hours >> minutes;
			start = {hours, minutes};
			sum += start - finish;
		}else break;
	}while(true);
	is.close();

	cout << sum.print();
	return 0;
}
