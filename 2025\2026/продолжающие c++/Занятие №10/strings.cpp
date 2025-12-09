#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespac std;

int main(){
	string s0 = "text value", s1, s2;//Инициализация значением
	cin >> s1;				//Ввод вплоть первого слова до пробела
	getline(cin, s2);		//Ввод одной строки из консоли(файла)
	
	cout << (s0+": "+s1) << "\n";//Разрешено складывать строки в одну
	
	//Для многократного сложения оптимально пользоваться потоком:
	stringstream ss;
	for(int i=0; i<min(s1,s2); ++i)//проход по элементам строки
		if(s1[i] == s2[i])	//Поиск одинаковых символов
			ss << s1[i];	//Записываем схожие символы в поток
	cout << ss.str()<<"\n";//вывод всего сложенного в поток
	
	//Сравнение строк
	cout << ((s1.compare(s2)==0)?"equal":"different") << "\n";
	//Подстроки:
	cout << s2.substr(2, s2.size()-4);
	//Указываем от какого символа, и длинну подстроки
	
	return 0;
} 
