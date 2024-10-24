#include <iostream>

using namespace std;

/*
Написать программу, получающую на вход 4 числа, которая выводит наименьшее и наибольшее из чисел, где бы они не стояли. 
Требования:
*обычные целые числа
*/

int main(){
	int n1, n2, n3, n4;				//Инициализируем 4 целых числа
	cin >> n1 >> n2 >> n3 >> n4; 	//Вводим 4 числа
	int min = n1, max = n1;			//Предполагаем что искомые это 1ое
	//По очереди сравниваем остальные числа с найденным и меняем его,
	//в том случае, если оно перестало быть минимальным.
	if(min > n2){
		min = n2;
	}
	if(min > n3){
		min = n3;
	}//Заметим, что сейчас min мог содержать как n1, так и n2!
	if(min > n4){
		min = n4;
	}
	//Аналогично сравниваем числа с предполагаемым максимальным
	if(max < n2){
		min = n2;
	}
	if(max < n3){
		min = n3;
	}
	if(max < n4){
		min = n4;
	}

	cout << "min: " << min << " max: " << max;
	return 0;
}

//Продвинутая версия с циклами и массивом:
int main(){
	int n[4];							//Здесь n - массив из 4 целых чисел
	for(int index=0; index<4; ++index)	//for() повторяет идущие за собой строки
		cin >> n[index];				//Единственная строка относящаяся к for()
	//Внутренний счётчик index проходит значения от 0 до 3, так как строго 3 < 4
	//++index - увеличивает счётчик на 1, за каждый проход цикла
	int min = n[0], max = n[0];
	//Аналогичное предположение, только 1ый элемент всегда с номером 0!
	for(int index=1; index<4; ++index){	//Много строк следующие за for(){внутри фигурных скобок}
		if(min > n[index])
			min = n[index];
		if(max < n[index])				//Одновременно проверям условия и для min, и для max
			max = n[index];
	}

	cout << "min: " << min << " max: " << max;
	return 0;
}


