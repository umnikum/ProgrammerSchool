#include <iostream>
#include <vector>

using namespace std;

int mainS(){
	//Создавать массив элементов можно 2мя способами
	int a[5],							//Указывать конкретную длинну
		b[] = {1, 2, 3, 4, 5};			//Задавать конкретные элементы
	//Стандартный вывод элементов массива, индесы нумеруются с 0!
	cout << "Array a:\n";
	for(int i=0; i<5; ++i)
		cout << a[i] << "\t";
	cout << endl;
	//По умолчанию элементы не обязаны содержать 0!!!!
	cout << "Array b:\n";
	for(int i=0; i<5; ++i)
		cout << b[i] << "\t";
	cout << endl;
	//Существует полезный класс vector подключаемый #include <vector>
	int size = 5;
	vector<int> c(5),					//Размер задаётся круглыми скобками
				d(size),				//Размер может храниться в другой переменной
				e{1, 2, 3, 4, 5};		//Можно задать конкретные элементы
	//В отличие от массива, вектор знает свой размер и по умолчанию забит 0
	cout << "vector c:\n";
	for(int i=0; i<c.size(); ++i)
		cout << c[i] << "\t";
	cout << endl;
	//begin и end итераторы пробегающиеся по элементам массива,
	//мы позже будем их проходить
	cout << "vector d:\n";
	for(auto i=d.begin(); i<d.end(); ++i)
		cout << *i << "\t";
	cout << endl;
	//Можно так пробегаться по всем элементам вектора, но индексы будут неизвестны
	cout << "vector e:\n";
	for(int element:e)
		cout << element << "\t";
	cout << endl;
	return 0;
}
