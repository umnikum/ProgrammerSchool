#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
 * Вам дано поле размеров N*N в котором каждой клетке соответствует высота.
 * В заданной клетке (X, Y) пробивается горный ключ. Найти координаты клетки
 * в которой закончится ключ, если вода стекает по такому закону:
 * beginner level
 * 1) Из "мокрой" клетки в соседнюю по ребру сухую с наименьшей высотой
 * 2a) Не может течь наверх или обратно
 * 3a) Концом ключа считается край поля или яма из которой не может уйти вода
 * intermediate level
 * 2b) Вода может течь обратно, если её уровень поднялся до предыдущей клетки
 * 3b) Концом ключа считается только край поля
 * 4) Попав в яму, вода поднимается до уровня самой низкой стенки и перетекает
 * через неё
 * advanced level
 * 5) Образуется заводь в нескольких соседних клетках с одним уровнем воды,
 * если ей некуда течь
 * Для уровня advanced вывести рисунок поля с пробелами для сухих клеток,
 * и с высотами уровня воды для ключа.
 */

class Riverland{
public:
	int size;
	vector<int> heights;


	/*Riverland(const int &size, const vector<int> &heights){
		this->size = size;
		this->heights = heights;
	}*/
	Riverland(const int &size, const vector<int> &heights):
		size(size), heights(heights){}
	Riverland(const string &file_name):
		size(0), heights(){
		ifstream ifs{file_name};
		ifs >> size;
		int amount = size*size;
		vector<int> location(amount);
		for(int i=0; i<amount; ++i)
			ifs >> location[i];
		ifs.close();
		heights = location;
	}


	bool is_boarder(const int &i, const int &j)const{
		return (i==0 or i==size-1 or j==0 or j==size-1);
	}


	int count_index(const int &i, const int&j)const{
		return i*size+j;
	}

	int count_x(const int &index)const{
		return index%size;
	}

	int count_y(const int &index)const{
		return index/size;
	}

	int search_shortest(const int &position)const{
		int shortest=position, check_position=position-1;
		shortest = (heights[shortest] >= heights[check_position])? check_position : shortest;
		check_position=position+1;
		shortest = (heights[shortest] >= heights[check_position])? check_position : shortest;
		check_position=position-size;
		shortest = (heights[shortest] >= heights[check_position])? check_position : shortest;
		check_position=position+size;
		shortest = (heights[shortest] >= heights[check_position])? check_position : shortest;
		return shortest;
	}


	vector<int> find_exit(const int &x, const int &y)const{
		vector<int> river;
		int i=y, j=x;
		river.push_back(count_index(i,j));
		while(!is_boarder(i, j)){
			int index = count_index(i,j),
				next_index=search_shortest(index);
			if(next_index != index){
				i = count_y(next_index);
				j = count_x(next_index);
				river.push_back(next_index);
			}else break;
		}
		return river;
	}


	string print()const{
		stringstream ss;
		int amount=size*size;
		for(int i=0; i<amount; ++i){
			ss << heights[i] << "\t";
			if(i%size == size-1)
				ss << "\n";
		}
		return ss.str();
	}
};

int main() {
	Riverland location("input.txt");
	cout << location.print();

	int x, y;
	cout << "Enter starting coordinates:\n";
	cin >> x >> y;

	cout << "From: ";
	auto river = location.find_exit(x, y);
	for(const int &index:river){
		cout << "(" << location.count_x(index) << ", "
				<< location.count_y(index) << ") -to-> ";
	}

	return 0;
}
