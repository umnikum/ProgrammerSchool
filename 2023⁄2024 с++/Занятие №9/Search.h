#ifndef SEARCH_H_
#define SEARCH_H_

#include <vector>

using namespace std;

//Ищем индекс 1 по нашему циклу, по умолчанию
//с несуществующего элемента, чтобы проверить 0 элемент
int getNext(vector<bool> circle, int begin = -1){
	//Начинаем со следующего индекса, запоминаем размер чобы постоянно не считать
	int index = begin+1, size = circle.size();
	//Понимаем что мы можем перескакнуть через конец массива
	while(!circle[index] and index<size){
		++index;
	}
	//Если не перескакнули, значит нашли
	if(index < size){
		return index;
	//Если перескакнули, нужно считать сначала
	}else{
		//Не указываем -1, так как работает его значение по умолчанию
		return getNext(circle);
	}
}
//Ищем расстояние по циклу между 2мя элементами
int getDistance(vector<bool> circle, int begin, int end){
	//Если они стоят по очереди всё хорошо
	if(end > begin)
		return end-begin;
	//Если нет, нужно учесть элементы до конца массива
	//и элементы до конечного
	else
		return circle.size() - begin + end;
}

#endif /* SEARCH_H_ */
