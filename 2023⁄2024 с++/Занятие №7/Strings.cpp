#include <iostream>
//Символьные строки
#include <string>

using namespace std;

int mainS() {
	//Инициализация переменной строки
	string line{"Hello!"};
	cout << line << endl;
	//Присвоение значения строке
	line = "World!";
	cout << line << endl;
	//Считывание строки с консоли
	getline(cin, line);
	cout << line << endl;
	//Считывание строки вплоть до элемента разрыва(перенос, пробел, табуляция)
	cin >> line;
	cout << line << endl;

	//Проверка пустая ли введённая строка
	if(line.empty())
		cout << "Empty!" << endl;
	else
		//Вывод длинны строки, если она не пустая
		cout << "Size: " << line.size() << endl;

	line = "Long content of single string variable xD";
	cout << line << endl;

	//Скромно удлинняем "длинную" строку
	line.insert(0, "Relatively ");
	//Вырезаем все символы после первой встречи 'х'
	line.erase(line.find("x"));
	cout << "Result: " << line << endl;

	//Выбираем подстроку которая начиналась со "str" длинной равной "string"

	string substring = line.substr(line.find("str"), "string"s.size());
	//Будет себя очень плохо вести если ничего не нашло!
	if(substring.compare("string") == 0)
		cout << substring << endl;
	//Повторим с введённой нами строкой!
	cin >> line;
	substring = line.substr(line.find("str"), "string"s.size());
	cout << substring << endl;
	return 0;
}
