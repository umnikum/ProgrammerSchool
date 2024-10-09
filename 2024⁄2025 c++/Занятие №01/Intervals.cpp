#include <iostream>

using namespace std;

int main(){
	//Переменные типа float, плавающая точка:
	float beg_1, end_1, beg_2, end_2;
	cout << "Enter frist interval:\n";
	//Культурно вводим интервалы с клавиатуры:
	cin >> beg_1 >> end_1;
	cout << "Enter second interval:\n";
	cin >> beg_2 >> end_2;
	
	//Сложное условие на попадание концов внутрь соседа:
	if((beg_1 <= end_2 and end_2 <= end_1) or (beg_2 <= end_1 and end_1 <= end_2)){
		cout << "Intervals overlap";
	//Не забываем ответить если условие не выполнилось:
	}else{
		cout << "Intervals do not overlap";
	}
} 
