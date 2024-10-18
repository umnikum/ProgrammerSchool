#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>

std::vector<std::string> split(const std::string &line){
    std::vector<std::string> args;
    auto previousIt = line.begin();
    auto nextIt = previousIt;
    do{
        nextIt = std::find(previousIt, line.end(), ' ');
        std::string arg = line.substr(previousIt-line.begin(), nextIt-previousIt);
        if(!arg.empty())
            args.push_back(arg);
        previousIt = nextIt+1;
    }while(nextIt != line.end());
    return args;
}

std::string to_string(int** array, const int &rows, const int &columns){
	std::stringstream ss;
	for(int i=0; i<rows; ++i)
		for(int j=0; j<columns; ++j)
			ss << array[i][j] << ((j==columns-1)?"\n":"\t");
	return ss.str();
}

using namespace std;

int main(){
	//Ввод всех строк содержащихся в файле
	vector<string> lines;
	ifstream ifs{"input.txt"};
	while(!ifs.eof()){
		string line;
		getline(ifs, line);
		if(!line.empty()){
			lines.push_back(line);
		}else break;
	}
	ifs.close();
	//Распознание чисел внутри строк и инициализация массива
	int rows_num = lines.size(), columns_num;
	int **values = new int*[rows_num];
	for(int i=0; i<rows_num; ++i){
		//Использование прлезной функции разбиения
		vector<string> args = split(lines[i]);
		columns_num = args.size();
		values[i] = new int[columns_num];
		for(int j=0; j<columns_num; ++j)
			values[i][j] = stoi(args[j]);
	}
	//Вывод массива в свой файл с помощую 2ой полезной функции
	ofstream ofs{"output.txt"};
	ofs << to_string(values, rows_num, columns_num);
	ofs.close();
	return 0;
}
