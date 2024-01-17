#include <iostream>
#include <vector>
#include "Search.h"

using namespace std;

/*
 * По кругу расставленны N 1 или 0. Они стоят с постоянным интервалом.
 * а) Посчитать интервал. б) Предположить что одна 1 стоит с ошибкой, найти её.
 */

int main() {
	int size;
	vector<bool> circle;

	cin >> size;
	circle.resize(size);
	int value;
	for(int i=0; i<size; ++i){
		cin >> value;
		if(value)
			circle[i] = true;
		else
			circle[i] = false;
	}

	//Ищем 1ую 1
	int begin{0}, end;
	while(!circle[begin]){
		++begin;
	}
	//Ищем следующую 1
	end = begin+1;
	//Придётся ограничиться концом цикла если 1 одна
	while(!circle[end] and end < size){
		++end;
	}

	//Выводим расстояние между ними
	cout << "Cycle is: " << end-begin << endl;
	cout << "Advanced part:\n";
	//Ищем 1ую единицу уже функцией
	begin = getNext(circle);
	//Ищем идущую за ней 1
	end = getNext(circle, begin);
	//Будем запоминать расстояние между 1 и позицию самой первой
	int distance = 0, next_distance = end-begin, start = begin;
	do{
		//Старый конец - новое начало
		begin = end;
		//Ищем новый конец
		end = getNext(circle, begin);
		//Запоминаем предыдущий цикл
		distance = next_distance;
		//Считаем новый цикл
		next_distance = getDistance(circle, begin, end);
	//продолжаем пока циклы равные или пока не вернулись в точку отсчёта
	}while(distance == next_distance and start != end);
	//Если циклы разные
	if(distance != next_distance){
		//Ошибка от начала старого интервала до конца нового, мы не знаем который неверный
		cout << "Mistake is between : " << begin-distance << " and " << end
			<< "\nConflicting cycles: " << distance << " and " << next_distance << endl;
	}else{
		//Если мы вернулись в самую 1ую 1цу, все циклы в порядке
		cout << "No mistake was found, cycle: " << distance;
	}
	return 0;
}
