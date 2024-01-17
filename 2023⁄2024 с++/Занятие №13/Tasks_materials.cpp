#include <iostream>
#include <fstream>
#include <vector>
#include <random>

static constexpr int size = 20;

size_t get_index(const int &i, const int &j){
	return i*size + j;}

int main(){
	auto gen = std::mt19937{std::random_device{}()};
	std::uniform_int_distribution<int> prob{0, 1}, cost{2, 9};
	std::vector<int> values(size*size);

	for(int i=0; i<size; ++i){
		values[get_index(i, i)] = 1;
		for(int j=i+1; j<size; ++j){
			const int num{prob(gen)*cost(gen)};
			values[get_index(i,j)] = num;
			values[get_index(j,i)] = num;
		}
	}

	std::ofstream ofs{"Materials/Advanced/tsk_1/test_04.in"};
	ofs << size << "\n";
	for(int i=0; i<size; ++i){
		for(int j=0; j<size; ++j){
			ofs << values[get_index(i,j)] << " ";
		}
		ofs << "\n";
	}
	return 0;
}
