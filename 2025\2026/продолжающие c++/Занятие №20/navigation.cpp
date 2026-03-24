#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//Подключаем нашу функцию split
#include "split.hxx"

using namespace std;

int main(){
	//Используем входной файл с матрицей
	ifstream ifs{"input.txt"};
	//Считываем первую строку чтобы узнать размерность матрицы
	string line;
	getline(ifs, line);
	auto row = split(line);
	//Записываем значения первой строки
	int j=1, n=row.size();
	int matrix[n*n];
	for(int i=0; i<n; ++i)
		matrix[i] = stoi(row[i]);
	//Продолжаем считывание вплоть до конца файла
	do{
		getline(ifs, line);
		row = split(line);
		for(int i=0; i<n; ++i)
			matrix[j*n+i] = stoi(row[i]);
		++j;
	}while(!ifs.eof());
	//Выводим полченную матрицу на экран
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j)
			cout << matrix[i*n+j] << "\t";
		cout << "\n";
	}
	
	ifs.close();
	return 0;
}
