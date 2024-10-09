#include <iostream>

using namespace std;

int main() {
	//Введём размер массива
	int n;
	cin >> n;
	//Инициализируем строки
	double **arr = new double*[n];
	//После чего инициализируес содержимое строк
	for(int i=0; i<n; ++i)
		arr[i] = new double[n];

	//Выведем массив  красивом табличном виде
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			//Разделяем столбцы табуляцией и строки переносом
			cout << arr[i][j] << ((j == n-1)?"\n":"\t");
		}
	}
	//Не заьываем удалить массив
	delete [] arr;
	return 0;
}
