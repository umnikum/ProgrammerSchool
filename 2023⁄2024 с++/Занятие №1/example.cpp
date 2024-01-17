 #include <iostream>

using namespace std;

int main(){
	cout << "This programm is dividing integer numbers" << endl << ">>";		//Поясниние при запуске о том что делает программа
	int in1, in2;
	cin >> in1 >> in2;								//Так можно вводить сразу 2 числа
	//cout << "Result of: " << in1 << " : " << in2 << " = " << in1/in2 << endl;
	//Выдаст неверный ответ, так как / для целых чисел делит с остатком
	float n1 = in1, n2 = in2, c = n1/n2;						//В ячейке с полноценный результат деления
	cout << "Result of: " << in1 << " : " << in2 << " = " << c << endl;
	return 0;									//Если делили на 0, то до этой строчки мы не дойдём
}
