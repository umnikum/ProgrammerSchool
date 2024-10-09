#include <iostream>

using namespace std;

/*
 * Функция это часть программы которую можно вызвоть когда угодно и сколько угодно
 * У функции есть:
 * имя - mid
 * тип - double
 * параметры - int len, double *arr
 * тело - {}
*/
double mid(int len, double *arr){
	//Заводим переменную сумму
	double sum=0.0;
	//Проходимся по каждому элементу массива arr[i]
	for(int i=0; i<len; i++)
		//Добавляем их к сумме
		sum += arr[i];
	//Возвращаем сумму делённую на количество элементов, что и требовалось:
	return sum/len;
}


double min(int len, double *arr){
	//Заводим переменную в которой будет храниться минимум
	//Присваиваем ей значение 1го элемента на случай если он и есть минимальный
	double min_ = arr[0];
	for(int i=0; i<len; i++)
		//Если следующий элемент массива arr[i] меньше min_
		if(min_ > arr[i])
		//Нам стоит перезаписать min_
			min_ = arr[i];
	//Возвращаем полученное значение
	return min_;
}

int main(){
	cout << "Enter array length:\n";
	int len;
	cin >> len;
	//Заводим массив длинны len
	double *arr = new double[len];
	
	for(int i=0; i<len; i++)
		cin >> arr[i];
	cout << "Ariphmetic middle value: " << mid(len, arr) <<
		 << "\nMinimum value: " << min(len, arr);
	//Не забываем удалить массив из памяти
	delete [] arr;
	return 0;
} 
