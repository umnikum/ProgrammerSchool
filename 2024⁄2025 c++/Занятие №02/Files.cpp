#include <iostream>
//Работа с файлами
#include <fstream>
//Удобная сложение строк
#include <sstream>
#include <string>

using namespace std;

int main(){
	int length, values[100];
	//Считываем из файла количество элементов < 100
	//Файл лежит вместе с нашей программой и называется input.txt!
	ifstream ifs{"input.txt"};
	ifs >> length;
	for(int i=0; i<length; ++i)
		ifs >> values[i];
	//Не забываем закрыть файл!
	ifs.close();

	//Выводим наши данные в файл output.txt
	//Если его не будет, программа автоматически его создаст!
	ofstream ofs{"output.txt"};
	for(int i=0; i<length; ++i)
		//Выводим только кратные 3 элементы
		if(values[i] % 3 == 0)
			ofs << values[i] << " ";
	ofs.close();

	//Как можно сократит вывод:
	/*
	stringstream ss;
	for(int i=0; i<length; ++i)
		if(values[i] % 3 == 0)
			ss << values[i] << " ";

	ofstream ofs{"output.txt"};
	ofs << ss.str();			//Записываем только 1ну сформированную строку
	ofs.close();
	*/
	return 0;
}
