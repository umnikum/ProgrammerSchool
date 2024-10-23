#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/*
 * Каждая функция имеет:
 * возвращаемый тип, в данном случае vector<string>
 * имя - split
 * набор входящих параметов с их типами - line
 */
std::vector<std::string> split(const std::string &line){
	//Создаём хранилище для разбиваемых слов
    std::vector<std::string> args;
    //Инициируем элементы(итераторы) пробегающие по строке
    auto previousIt = line.begin();
    auto nextIt = previousIt;
    do{
    	//Функция find() возвращает итератор на начало найденного элемента или конец строки
        nextIt = std::find(previousIt, line.end(), ' ');
        //Метод substring() по индексу и длинне возвращает подстроку
        std::string arg = line.substr(previousIt-line.begin(), nextIt-previousIt);
        //Учитываем случай с двойными пробелами, когда строка пустая
        if(!arg.empty())
            args.push_back(arg);
        //Переходим в следующий элемент
        previousIt = nextIt+1;
    //Выходим когда дошли до конца строки
    }while(nextIt != line.end());
    //Не забываем вернуть полученный вектор
    return args;
}

using namespace std;

int main() {
	string line;
	getline(cin, line);
	//Пользуемся автоматическим проходом по вектору
	for(auto word:split(line))
		cout << word << "\n";
	return 0;
}
