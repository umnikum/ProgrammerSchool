#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	//Флажок состояния входа
	int user_index=-1, user_amount=3;
	//Наши системные переменные строки
	string command, message=">>";
	//В случае 1го пользователя, строки с его данными
	//string user="vasya", password="1234", secret="secret!";
	//В случае нескольких пользователей наборы(векторы) строк:
	vector<string> users = {"vasya", "petya", "kolya"},
					passwords = {"1234", "psd", "qwerty"},
					secrets = {"secret!", "petin secret!", "nothing to hide!"};
	//Бесконечный цикл до ввода ключевого слова
	do{
		//Обязательное сообщение перед вводом комманды
		cout << message;
		//Ввод комманды
		cin >> command;
		//Дерево разбора команд, для строк это необходимость
		if(command.compare("login")==0){
			//Ввод имени пользователя
			string user_name;
			cin >> user_name;
			//Проверка что оно корректное
			user_index=0;
			while(user_index < user_amount){
				if(user_name.compare(users[user_index])==0){
				//Ввод пароля
					string user_password;
					cout << "Enter password:\n>>";
					cin >> user_password;
					//Проверка что он тоже корректен
					if(user_password.compare(passwords[user_index])==0){
						message = user_name + ">>";
					}else{
						//Не забываем про ошибки ввода!
						cout << "Wrong password!\n";
						user_index = -1;
					}
					break;
				}
				++user_index;
			}
			if(user_index >= user_amount){
				cout << "User not found!\n";
				user_index = -1;
			}
			//Команда выхода из пользователя
		}else if(command.compare("logout")==0 and user_index>=0){
			message = ">>";
			user_index = -1;
		//Команда показывающая секрет пользователя
		}else if(command.compare("show")==0){
			//Выводим секрет только если зашли под именем пользователя
			if(user_index>=0){
				cout << secrets[user_index] << "\n";
			}else{
				cout << "access denied!\n";
			}
		}
	//Выходим только по команде exit с любого пользователя
	}while(command.compare("exit") != 0);
	return 0;
}
