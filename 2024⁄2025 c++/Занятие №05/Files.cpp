#include <iostream>
//Работа с файлами
#include <fstream>
//Удобная сложение строк
#include <sstream>
#include <string>

using namespace std;

int main(){
	string conteinment;
	//Считываем из файла количество элементов < 100
	//Файл лежит вместе с нашей программой и называется input.txt!
	ifstream ifs{"input.txt"};
	ifs >> containment;
	//Не забываем закрыть файл!
	ifs.close();

	//Выводим наши данные в файл output.txt
	//Если его не будет, программа автоматически его создаст!
	ofstream ofs{"output.txt"};
	ofs << containment;
	ofs.close();
	
	return 0;
}
