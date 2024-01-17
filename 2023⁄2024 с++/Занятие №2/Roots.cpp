 #include <iostream>

using namespace std;

int main(){
	double a, b, c;								//double - длиннее float, лучше пользоваться им
	cout << "Looking for roots of equation: a*x^2 + b*x + c = 0" << endl	//Правило хорошего тона:
	<< "Enter coeeficients a, b, c:" << endl;				//Рассказываем что мы собираемся делать
	cin >> a >> b >> c;
	if(a == 0.0){								//Условие отсутствия члена x^2
		if(b == 0.0){							//Условие отсутствия члена x
			if(c == 0.0){						//Условие отсутствия свободного члена
				cout << "x - can be anything" << endl;
			}else{							//В уравнении только константа != 0
				cout << "There are no roots!" << endl;
			}
		}else{
			cout << "There is one root!" << endl;			//Уравнение вида b*x + c =0
		}
	}else{									//Полноценное квадратное уравнение
		double d = b*b - 4*a*c;						//Считаем дискриминант
		if(d < 0){							//Условие несуществования корней
			cout << "There are no real roots!" << endl;
		}else if(d == 0){						//Корни не различимы (всего один)
			cout << "There is one root!" << endl;
		}else{								//2 полноценных различных корня
			cout << "There are two roots!" << endl;
		}
	}
	return 0;
}
