#include <iostream>
#include <fstream>
#include <vector>
#include <string>
//Подключаем нашу функцию split
#include "split.hxx"

using namespace std;

//backtracking - реализация функции шага
int step(const int &last, vector<int> &trail, const int &n, const int *matrix){
	int c = trail.back();
	//Если нашли путь в конец идём туда
	if(matrix[c][last] != 0)
		return matrix[c][last];
	//Иначе перебираем все города в которые можно пройти из последнего
	for(int i=0; i<n; ++i){
		//Если путь в такой город есть, делаем шаг в этот город
		if(matrix[c][i] != 0){
			//if("i не встречался в пути"){} - TODO подумать как это реализовать самостоятельно!
			trail.push_back(i);
			int len = step(last, trail, n, matrix);
			//Не забываем вернуться из следующего города
			trail.pop_back();
			//Если нашли путь, возвращаемся дальше, набирая длинну пути в обратном направлении
			if(len > 0){
				return len + matrix[c][i];
			}
		}
	}
	//Если ничего найти не удалось, возвращаем 0, сообщающий о неудаче поиска
	return 0;
}


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
