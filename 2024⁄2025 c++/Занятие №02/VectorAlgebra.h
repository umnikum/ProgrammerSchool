#ifndef VECTORALGEBRA_H_
#define VECTORALGEBRA_H_

#include <cmath>
#include <vector>
#include <string>
#include <sstream>


//Оставим себе возможность менять тип значений между float и double
using val_type = double;
//Будем использовать стандартный вектор в качестве координат
using vec_type = std::vector<val_type>;

//Простейший унарный оператр модуля:
val_type abs(const vec_type &vec){
	/*
	 * Принимаем на вход:
	 * const - неизменное значение
	 * vec_type - именно тот тип вектора с корторым м собирались работать
	 * & - константная ссылка позволяет принимать rvalue т.е. сгенерированные значения
	 * например: {0.0, 1.0, 0.0} не имеет своей переменной, но метод сможет его принять
	 */
	val_type result = 0.0;
	//Проходимся по всем значениям не переживая за тип:
	for(auto val:vec)
		result += val*val;
	//Возвращаем математический корень из посчитанной суммы
	return std::sqrt(result);
}

//Унарный оператор обратного значения, позволяет вернуть противоположный вектор:
vec_type operator-(const vec_type &vec){
	//Сразу создаём копию полученного вектора:
	vec_type result{vec};
	for(val_type &val:result)
		//Так как мы пользуемся ссылками, мы просто обращаем их значения
		val = -val;
	//Возвращаем уже полученный вектор:
	return result;
}

//Ещё одна полезная функция для выведения наших векторов в консоль:
std::string to_string(const vec_type &vec){
	std::stringstream ss;
	ss << "(";
	//Чтобы отследить конец вектора пользуемся индексами:
	for(std::size_t i=0; i<vec.size(); ++i){
		ss << vec[i];
		//Добавляем после каждого значения разделитель, либо конечную скобку:
		ss << ((i == vec.size()-1)?")":", ");
	}
	//Возвращаем полученную строку:
	return ss.str();
}

//Бинарный оператор сложения, называется бинарным так как использует 2 значения на входе:
vec_type operator+(const vec_type &left, const vec_type &right){
	//Принято называть значения l и r от полных left и right
	//Создаём копию left чтобы не переживать за размер и уже иметь часть значений
	vec_type result{left};
	for(std::size_t i=0; i<left.size(); ++i)
		result[i] += right[i];
	return result;
}
//Замечание! Подмайте почему это не всегда будет работать, и что в этом случае лучше делать


//Для удобства имеет смысл ввести оператор добавления(+=)
vec_type operator+=(vec_type &left, const vec_type &right){
	//Заметим что часть const у left ушла! Мы собираемся менять сами значения вектора
	for(std::size_t i=0; i<left.size(); ++i)
		left[i] += right[i];
	//Для того чтобы делать цепочки выражений с += будем возвращать значение left, хотя это не обязательно
	return left;
}

//Если вас интересует готовая координатная имплементация: https://ggt.sourceforge.net/

#endif /* VECTORALGEBRA_H_ */
