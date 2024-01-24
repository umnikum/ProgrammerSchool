#include <iostream>
#include <sstream>

using namespace std;

int main() {
	//Вставля 0 перед номером, мы указываем что число в 8ричной(Octal) системе
	int _8_var=0100, _16_var;
	//Чтобы инициализировать число в 16ричной(Hex) системе нужно немного постараться
	istringstream("ff") >> hex >> _16_var;
	cout << "Octal: " << _8_var  << "\nHex: " << _16_var << "\nInsert hex type num:\n";
	//С вводом же достаточно дописать hex перед переменной
	cin >> hex >> _16_var;
	cout << "Your number in decimal: " << dec << _16_var << "\n";

	//Ссылка на переменную обозначается & перед названием ссылки
	int &l=_16_var;
	//В ней хранится значение переданной переменной
	cout << "Variable value: " << _16_var << ", Link value: " << l << "\n";
	//Если изменить значение переменной, поменяется и значение в ссылке
	_16_var++;
	cout << "Variable value: " << _16_var << ", Link value: " << l << "\n";
	//Если изменить значение в ссылке, то изменится и переменная
	l++;
	cout << "Variable value: " << _16_var << ", Link value: " << l << "\n";
	//Адрес переменной закреплён за ссылкой
	cout << "Variable address: " << &_16_var << ", Link address: " << &l << "\n";

	//Указатель на переменную обозначается * перед именем указателя
	//Указатель равен адресу переменной, который получается & перед именем переменной
	int *p = &_16_var;
	//Можно посмотреть соответствующий адрес, а значение * перед именем указателя
	cout << "Address: " << p << ", Value: " << *p << "\n";
	//Можно увеличить значение которое лежит по хранимому адресу
	(*p)++;
	cout << "Address: " << p << ", Value: " << *p << "\n";
	//Можно увеличить сам адрес... Только результат не гарантирован
	p++;
	cout << "Address: " << p << ", Value: " << *p << "\n";
	//Заметим что ссылка сохранила значение, когда указатель уже его потерял
	cout << "Link value: " << l << ", Pointer value: " << *p << "\n";
	//Также к указателю можно обращаться p[0]
	return 0;
}
