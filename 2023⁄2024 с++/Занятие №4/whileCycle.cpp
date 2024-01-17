#include <iostream>

using namespace std;

/*
 * Найти наименьший простой делитель введённого числа
 */

int mainWhile(){
	int num;
	cin >> num;
	//Результат будет записывать в result
	int result = 2;
	//Цикл while() выполняется пока условие в скобках верно
	while(num % result != 0){
		result++;
	}
	cout << result;
	//На случай введения 1 или 0
	result = 2;
	while((num % result != 0)&&(result < num)){
		result++;
	}
	cout << result;
	//do{}while(); сначала выполняет свои команды, а затем проверяет условие
	//Поэтому можно задать начальное значение 1, которое сразу увеличится
	result = 1;
	do{
		result++;
	}while((num % result != 0)&&(result < num));
	return 0;
}
