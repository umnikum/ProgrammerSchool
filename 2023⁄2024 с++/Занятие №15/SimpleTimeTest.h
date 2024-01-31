#ifndef SIMPLETIMETEST_H_
#define SIMPLETIMETEST_H_

#include <iostream>
//Подключаем библиотеку времени <chrono>:
#include <chrono>

using namespace std;

void simple_time_test(){
	//auto автоматически определяет тип полученного значения time_point
	auto time_start = chrono::system_clock::now();
	//Выполняем простую операцию ++ МНОГО раз:
	for(size_t i=0; i<1'000'000'000; ++i);
	//Аналогично считываем системное время:
	auto time_end = chrono::system_clock::now();
	//Разность временных точек является объектом класса длительность(duration)
	cout << "Time spent(++): "
		//Чтобы вывести время в долях секунды придётся немного извернуться:
		<< static_cast<double>(chrono::nanoseconds(time_end - time_start).count())/1'000'000'000
		<< " seconds\n";
	time_start = chrono::system_clock::now();
	//Проверим скорость другой операции:
	for(size_t i=0; i<1'000'000'000; i+=1);
	time_end = chrono::system_clock::now();
	cout << "Time spent(+=): "
		<< static_cast<double>(chrono::nanoseconds(time_end - time_start).count())/1'000'000'000
		<< " seconds\n";
	time_start = chrono::system_clock::now();
	//Проверим скорость другой операции:
	for(double i=0.0; i<1e+9; i+=1.0);
	time_end = chrono::system_clock::now();
	cout << "Time spent(double): "
		<< static_cast<double>(chrono::nanoseconds(time_end - time_start).count())/1'000'000'000
		<< " seconds\n";
}

#endif /* SIMPLETIMETEST_H_ */
