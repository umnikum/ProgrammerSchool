#ifndef CODER_H_
#define CODER_H_ 

#include <string>
#include <map>
#include <random>

//Создаём класс шифровщик
class Coder{
private:
//Скрываем ключи от посторонних глаз
	std::map<char, char> cipher, decipher;
public:
//Конструктор забивает случайную перестановку шифруемых символов
	Coder(){
		//Генератор из <random>
		std::mt19937 gen{std::random_device{}()};
		char from='a', to='z';
		int range = (to-from+1);
		//Для каждого символа:
		for(char key=from; key<=to; ++key){
			char value;
			//Обязательно чтобы символ был новым
			do{
				value = from+(gen()%range);
			}while(decipher.count(value) > 0);
			//Запись в данные сгенерированных параметров
			cipher[key]=value;
			decipher[value]=key;
		}
	}
	//Метод code возвращает шифрованную строку не меняя данных класса
	std::string code(std::string line)const{
		//Для каждой ссылки на символ:
		for(char &c:line)
			c = cipher.at(c);
		return line;
	}
	//Метод code возвращает расшифрованную строку не меняя данных класса
	std::string decode(std::string line)const{
		for(char &c:line)
			c = decipher.at(c);
		return line;
	}
};

#endif /* CODER_H_ */
