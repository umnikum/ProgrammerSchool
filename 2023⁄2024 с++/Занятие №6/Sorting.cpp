#include <iostream>
//Заметим дополнительные пакеты, вектор для удобных массивов
#include <vector>
//Алгоритм для поиска и сортировки
#include <algorithm>

using namespace std;

int main() {
	int amount;
	cout << "Enter amount of elements: ";
	cin >> amount;

	//Можно вводить вектор поэлементно, расширяя его длинну
	//Команда .push_bakc(element) добавляет элемент в конец
	/*
	 * vector<int> elements{};
	 * for(int i=0; i<amount ++i){
	 * 		int element;
	 * 		cin >> element;
	 * 		elements.push_back(element);
	 * }
	 */
	//Можно заранее задать количество элементов
	//и просто присваивать значения элементам
	vector<int> elements(amount);
	for(int i=0; i<amount; ++i)
		cin >> elements[i];

	//Сортируем массив, хотя для этого есть специальная команда
	//sort(elements.begin(), elements.end());
	//Для каждого элемента проверяем:
	for(int from=1; from<amount; ++from)
		//Все предыдущие элементы(конечно кроме самого)
		for(int to=from-1; to>=0; --to)
			//Проверяем рядом стоящие элементы
			if(elements[to+1] < elements[to]){
				//Меняем элементы местами, хотя для этого тоже есть команда
				//swap(elements[to+1], elements[to]);
				int memory = elements[to];
				elements[to] = elements[to+1];
				elements[to+1] = memory;
			//break - команда насильно завершающая 1ин цикл
			//Если элементы уже стоят по порядку не нужно дальше ничего менять
			}else break;
	//Выводим элементы массива по порядку
	for(int element:elements)
		cout << element << "\t";

	return 0;
}
