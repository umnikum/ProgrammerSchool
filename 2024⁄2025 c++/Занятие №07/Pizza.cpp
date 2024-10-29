#include <iostream>
#include <vector>
#include <string>

using namespace std;

//Класс называется с большой буквы чтобы отличать его от переменных
class Pizza{
//Пока будем объявлять внутренние объекты публичными
public:
	//Поля это внутренние переменные, которые содержатся в классе
	string name;
	int size;
	double price;
	vector<string> ingredients;

	//Конструктор это особый метод который собирает переменную класса по заданным параметрам
	Pizza(const string &name,
		  const int &size,
		  const double &price,
		  const vector<string> &ingredients)://Здесь мы забиваем значения внутрих переменных данными полученными извне
		  name{name},
		  size{size},
		  price{price},
		  ingredients{ingredients}{
			  //Здесь выполняются операции по соданию оного экземпляра
			  cout << "Cooking " << name << " pizza:\n"
				   << "Making dough of " << size << " cm size\n"
				   << "Putting ingredients:\n";
			  for(auto ingredient:ingredients)
				  cout << ingredient << "\t";
			  cout << "\nBaking for 30 minutes\n"
				   << "Ready! Price is: $" << price << "\n";
		  }

	//Методы это функции применимые к классу
	void print()const{
		//Методы уже знают все поля класса и не нуждаются в дополнительных параметрах
		cout << name << " pizza (" << size << " cm) - $" << price;
	}
};


int main() {
	//Вызываем конструктор пиццы:
	Pizza pepperoni{"Pepperoni", 30, 14.99, {"Pepperoni", "Mozarella", "Barbecue sauce", "Tomato"}};
	//Просим её вывестись на экран как она это умеет
	pepperoni.print();
	return 0;
}
