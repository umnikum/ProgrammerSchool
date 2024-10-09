#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <iostream>
#include <vector>

//Простейшая процедура не использующая никакие параметры:
void simple_wellcome(){
	std::cout << "Hello World!!!";
}

//Функция степени возводящая значение value в степень power
double pow(double value, int power){
	//На вход функция получает 2 параметра
	double result = value;
	for(int i=0; i<power; ++i)
		result += value;
	//Возвращает 1ин результат типа double
	return result;
}

//Функция обнуления значений верктора вещественных чисел:
void abnull(std::vector<double> &vec){
	//Заметим ссылку & - она означает что функция обязана работать с переменной
	for(double &val:vec)
		//Для каждого хранящегося в vec значения записываем в него 0.0
		val = 0.0;
}


#endif /* FUNCTIONS_H_ */
