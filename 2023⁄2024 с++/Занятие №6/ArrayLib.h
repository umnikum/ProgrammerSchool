#ifndef ARRAYLIB_H_
#define ARRAYLIB_H_

#include <iostream>
#include <vector>

using namespace std;

//Чтобы каждый раз не вводить массив, удобно иметь функцию ввода.
//Она будет выдавать введённый пользователем массив
vector<int> readArray(){
	int amount;
	cout << "Enter amount of elements: ";
	cin >> amount;
	vector<int> elements(amount);
	for(int i=0; i<amount; ++i)
		cin >> elements[i];
	return elements;
}
//В дальнейшем хватит записи: vector<int> arr = readArray();

//Аналогично удобно иметь функцию вывода массива
//Заметим что у функции есть входной параметр,
//который нужно будет указывать в скобках
void printArray(vector<int> array){
	for(int element:array)
		cout << element << "\t";
}
//В дальнейшем хватит записи: printArray(arr);

//Аналогично выводу создаём сортировку, но указываем ссылку на массив
void bubbleSort(vector<int> &array){
	for(int from=1; from<array.size(); ++from)
		for(int to=from-1; to>=0; --to)
			if(array[to+1] < array[to])
				swap(array[to+1], array[to]);
			else break;
}
//В дальнейшем хватит записи: bubbleSort(arr);


#endif /* ARRAYLIB_H_ */
