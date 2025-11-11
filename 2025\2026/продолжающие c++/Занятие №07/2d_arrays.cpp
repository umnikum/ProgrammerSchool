#include <iostream>

using namespace std;

int main(){
	//Иниицализация стандартного двумерного массива
	int size = 10;
	//Инициализируем массив строк
	int **arr = new int*[size];
	for(int i=0; i<size; ++i){
		//По очереди инициализируем строки
		arr[i] = new int[size];
	}
	
	//Заполняем массив 1 по диагонали
	for(int i=0; i<size; ++i){
		arr[i][i] = 1;
	}
	//Выводим на экран содержимое
	for(int i=0; i<size; ++i){
		for(int j=0; j<size; ++j){
			cout << arr[i][j] << "\t";
		}
		cout << "\n";
	}
	
	//Процедура удаления массива
	for(int i=0; i<size; ++i){
		//В обратном порядке зачищаем строки
		delete [] arr[i];
	}
	//После чего удаляем сам массив
	delete [] arr;
	return 0;
}
