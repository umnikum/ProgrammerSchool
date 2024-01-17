#include <iostream>

using namespace std;

/*
 * Поменять местами элементы [i][j] с [j][i] в двумерном массиве
 */

int main() {
	//Двумерный массив отличается дополнительной скобкой
	int rows, columns, arr2d[10][10];

	//Для ввода уже нужны 2 размера, столбцы и строки
	cout << "Enter row and column numbers:(lower then 10)\n";
	cin >> rows >> columns;
	cout << "Enter elements:\n";
	for(int i=0; i<rows; ++i)
		for(int j=0; j<columns; ++j)
			//К элементу обращаются 2мя индексами, сначала строка
			cin >> arr2d[i][j];


	//Здесь меняем элементы которые просили
	for(int i=0; i<rows; ++i)
		//Немного различаются неквадратные случаи
		if(i < columns)
			for(int j=i+1; j<columns; ++j)
				swap(arr2d[i][j], arr2d[j][i]);
		else
			for(int j=0; j<columns; ++j)
				swap(arr2d[i][j], arr2d[j][i]);

	//Выводим результат
	cout << "Result:\n";
	for(int i=0; i<columns; ++i){
		for(int j=0; j<rows; ++j)
			cout << arr2d[i][j] << "\t";
		//Заметим что придётся после каждой строки делать перенос
		cout << endl;
	}
	return 0;
}
