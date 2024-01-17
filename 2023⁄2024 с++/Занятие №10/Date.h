#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <sstream>
#include <cassert>



class Date{
protected:
	unsigned int day;
	unsigned int month;
	unsigned int year;
public:
	Date(const unsigned int &day, const unsigned int &month, const unsigned int &year=2023):
		day{day}, month{month}, year{year}{

	}
	//Конструкторов может быть несколько
	Time(const unsigned int &seconds=0){
		//Например здесь мы получаем время по количеству секунд
		unsigned int counter=seconds;
		this->seconds = counter%60;
		counter /= 60;
		minutes = counter%60;
		counter /= 60;
		hours = counter%24;
	}
	//Конструктор копирования из готовой переменной
	Time(const Time &time):
		hours{time.hours}, minutes{time.minutes}, seconds{time.seconds}{}

	/*
	 * Здесь мы даём доступ к значениям счётчиков, но не к замене
	 * Пользователь не может поменять значение минут на 61,
	 * только получить копию счётчика.
	 * const после круглых скобок говорит о том, что метод
	 * не будет менять значение переменной времени.
	 */
	unsigned int get_hours()const{return hours;}
	unsigned int get_minutes()const{return minutes;}
	unsigned int get_seconds()const{return seconds;}

	//Максимально упрощённый оператор добавления секунды
	Time operator++(){
		++seconds;
		if(seconds > 59){
			++minutes;
			seconds -= 60;
		}
		if(minutes > 59){
			++hours;
			minutes -= 60;
		}
		hours %= 24;
		return *this;
	}
	//Более сложная версия оператора сложения, использующая конструктор
	Time operator+(const Time &time)const{
		return Time{to_seconds()+time.to_seconds()};}
	//Вычитание отличается цикличностью времени в случае отрицательных чисел
	Time operator-(const Time &time)const{
		unsigned int my_time{to_seconds()}, diff_time{time.to_seconds()};
		return (my_time > diff_time)? Time{my_time-diff_time} : Time{24*60*60 + my_time-diff_time};
	}

	Time operator+=(const Time &time){
		*this = *this + time;
		return *this;
	}

	//friend - метод вне класса, который применим к нему
	friend bool operator==(const Time &a, const Time &b){
		return a.hours==b.hours and a.minutes==b.minutes and a.seconds==b.seconds;}
	//Не забываем про особые условия упорядоченных счётчиков
	friend bool operator<(const Time &a, const Time &b){
		if(a.hours != b.hours){
			return a.hours < b.hours;
		}else if(a.minutes != b.minutes){
			return a.minutes < b.minutes;
		}else return a.seconds < b.seconds;
	}
	//Это описание метода, чтобы его можно было вынести наружу
	std::string print(const char &mode = 'd')const;
//Приватные члены существуют только внутри класса
private:
	/*
	 * Метод который сводит время к одному unsigned int,
	 * что убирает необходимость класса,
	 * зато позволяет удобно складывать и вычитать времена.
	*/
	unsigned int to_seconds()const{
		return seconds + minutes*60 + hours*60*60;}
};

//Если метод вынесен наружу, придётся указать откуда он Time::
std::string Time::print(const char &mode)const{
	std::stringstream ss;
	/*
	 * Мод определяет способ вывода класса в строку
	 * switch(переменная) перебирает значения переменной
	 */
	switch(mode){
	//Случай если mode == 's' short
	case 's':
		ss << hours%12 << ':';
		if(minutes < 10)
			ss << '0';
		ss << minutes << ' ';
		//Правильно выводим полуденный формат
		(hours >= 12)? ss << "pm" : ss << "am";
		//Не забываем прекратить перебор
		break;
	//Случай если mode == 'l' long
	case 'l':
		ss << hours%12 << ':';
		if(minutes < 10)
			ss << '0';
		ss << minutes << ':';
		//Добавляем секунды
		if(seconds < 10)
			ss << '0';
		ss << seconds << ' ';
		(hours >= 12)? ss << "pm" : ss << "am";
		break;
	//Случай если mode == 'd' default
	case 'd':
	//Либо если иной символ был передан
	default:
		//Выводим стандартный формат времени
		if(hours < 10)
			ss << '0';
		ss << hours << ':';
		if(minutes < 10)
			ss << '0';
		ss << minutes;
	}
	return ss.str();
}

#endif /* DATE_H_ */
