#include <iostream>
#include <algorithm>
#include "SimpleTimeTest.h"
#include "FileLoading.h"
#include "Sort.h"

using namespace std;

int main_main() {
	simple_time_test();
	//Значения получаются из сгенерированного файла
	vector<int> values(load_vector_from_file("lots_of_values.in")), values_copy(values);
	auto time_start = chrono::system_clock::now();
	//Запускаем нашу пузырьковую, обычную сортировку:
	bubble_sort(values);
	auto time_end = chrono::system_clock::now();
	cout << "Time spent(bubble_sort): "
		<< static_cast<double>(chrono::nanoseconds(time_end - time_start).count())/1'000'000'000
		<< " seconds\n";
	time_start = chrono::system_clock::now();
	//Пользуемся самой оптимизированной сортировкой:
	sort(values_copy.begin(), values_copy.end());
	time_end = chrono::system_clock::now();
	cout << "Time spent(optimal_sort): "
		<< static_cast<double>(chrono::nanoseconds(time_end - time_start).count())/1'000'000'000
		<< " seconds\n";
	return 0;
}
