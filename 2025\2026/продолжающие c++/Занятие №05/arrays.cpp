#include <iostream>
#include <vector>

using namespace std;

int main(){
	int arr[10]; //Массив из 10 элементов, заполненный нулями по умолчанию
	
	for(int i=0; i<10; ++i){
		cin >> arr[i];//Ввод элементов массива
	}
	
	for(int i=9; i>=0; --i){
		cout << arr[i] << "\t";//Вывод в обратном порядке
	}
	cout << "\n";
	for(int i=0; i<10; ++i){
		cout << arr[9-i] << "\t";//Индексы могут быть математическими выражениями
	}
	cout << "\n";
	
	vector<int> vec(arr);//Вектор это массив с переменным размеров
	for(int i:vec){//По нему пожно проходиться напрямую
		cout << i << "\t";
	}
	
	return 0;
}
