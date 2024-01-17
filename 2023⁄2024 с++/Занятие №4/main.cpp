#include <iostream>

using namespace std;

/*
 * Умелый дровосек рубит дерево по 1 единице толщины за удар, каждый 4ый удар вдвое сильнее.
 * Пользователь задаёт толщину дерева, определить каким ударом дерево будет срублено.
 */

int main(){
	//Храним переменные с количеством ударов и толщиной дерева
	int hit_count, width;
	cout << "Lumberjack is hucking a tree, how wide is it?\n";
	cin >> width;
	//Аккуратный ввод ширины дерева
	//Рубим дерево с 1го удара, пока его толщина не равна нулю, по 1му удару
	for(hit_count = 0; width>0; ++hit_count){
		//Если удар 4ый, то он критический
		if(hit_count%4 == 0){
			width-=2;
		//Иначе обычный
		}else{
			width --;
		}
	}
	//Выводим полученный результат
	cout << "Lumberjack cuts it in " << hit_count << " hits";
	return 0;
}
