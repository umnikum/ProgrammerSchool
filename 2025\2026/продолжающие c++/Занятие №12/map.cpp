#include <iostream>
#include <string>
//Необходимо подключть класс в нашу программу
#include <map>

using namespace std;

int main(){
	//map требует указания 2х типов, 1ый указывает ключ, второй значения хранящиеся в структуре
	map<int, int> values{};
	//Задавать элементы можно несколькими спообами
	values[3] = 13;//Простейший, но он всегда создаёт 3ий элемент, даже если хотелось просто проверить значение
	values.emplace(7, 25);//Более безопасный метод, хотя несколько многословнее своего аналога
	//Чтобы узнать записано то или иное значение, можно использовать count:
	if(values.count(3) > 0)
		cout << "found key 3\n";
	else cout << "key 3 not found\n";
	
	if(values.count(2) > 0)
		cout << "found key 2\n";
	else cout << "key 2 not found\n";
	//Проходиться по всем значениям можно по парам значений
	for(pair<int, int> key_value:values){
		//first отвечает за ключ, second - за значение
		cout << key_value.first << "\t" << key_value.second << "\n";
	}
	//map можно изначально задавать фигрными скобками:
	map<string, int> ages{{"Vasiliy", 12}, {"Peter", 10}, {"Nikita", 14}};
	//Так как ключём может быть и строка, то строчное значение тоже можно передавать в квадратные скобки map
	cout << "Peter age is - " << ages["Peter"] << "\n";
	for(pair<string, int> key_value:ages){
		cout << key_value.first << "\t" << key_value.second << "\n";
	}
	return 0;
}
