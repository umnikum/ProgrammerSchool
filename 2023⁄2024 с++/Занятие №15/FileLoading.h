#ifndef FILELOADING_H_
#define FILELOADING_H_

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

std::vector<int> load_vector_from_file(const std::string &file_name){
	std::vector<int> result;
	std::ifstream ifs{file_name};
	int number;
	do{
		ifs >> number;
		result.push_back(number);
	}while(!ifs.eof());
	return result;
}

void save_vector_to_file(const std::string &file_name, const std::vector<int> &values){
	std::ofstream ofs{file_name};
	const size_t size = values.size();
	for(size_t i=0; i<size; ++i){
		ofs << values[i] << "\t";
		if(i%20 == 19)
			ofs << "\n";
	}
}

#endif /* FILELOADING_H_ */
