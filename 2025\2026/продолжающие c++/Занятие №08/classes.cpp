#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Класс объявляется своим именем после ключевого слова
class Student{
//Нужно объявить публичными поля класса для их использования в коде
public:
	//Рекомендуется начать с данных хранящихся внутри класса
	string name, surname;
	//Может содержать слоные структуры
	vector<int> grades{};//По умолчанию вектор пустой и инициализируется сразу
	
	//Конструктор создаёт экземпляр класса и заполняет поля перечисленные выше при помощи заданных параметров
	Student(string name, string surname=""):name{name}, surname{surname}{/*Здесь можно написать необходимые команды*/}//Краткая форма заполнения значений
	
	//Методом называется внутренняя функция которая знает о полях класса и способна задействовать их при выполнении
	double average()const{
		double summ = 0.0;
		for(auto grade:grades) summ += static_cast<double>(grade);//grades здесь является полем класса
		return summ/static_cast<double>(grades.size());
	}
};

int main(){
	//Вызываем конструкторы для  переменных типа нашего класса
	Student ann{"Anna", "Ivanova"}, pavel{"Pavel", "Sidorov"};
	//Обращаемся к полю класса grades через . и заполняем его значениями
	ann.grades.push_back(3);
	ann.grades.push_back(4);
	ann.grades.push_back(4);
	pavel.grades.push_back(4);
	pavel.grades.push_back(5);
	pavel.grades.push_back(4);
	pavel.grades.push_back(3);
	//Вызываем метод average через . и получаем значения средних оценок
	cout << ann.name << " average:" << ann.average()
		 << pavel.name << " average:" << pavel.average();
	return 0;
} 
