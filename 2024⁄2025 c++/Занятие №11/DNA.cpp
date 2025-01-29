#include <iostream>
#include <string>
#include <map>
#include <fstream>

bool is_equal(const std::map<char, int> &counters_1, const std::map<char, int> &counters_2){
	for(auto pair:counters_1){
		if(pair.second != 0)
			if(counters_2.count(pair.first) > 0){
				if(pair.second != counters_2.at(pair.first))
					return false;
			}else return false;
	}
	for(auto pair:counters_2){
		if(pair.second != 0)
			if(counters_1.count(pair.first) > 0){
				if(pair.second != counters_1.at(pair.first))
					return false;
			}else return false;
	}
	return true;
}

void print(const std::map<char, int> &counters){
	for(auto pair:counters)
		if(pair.second > 0)
			std::cout << pair.first << ": " << pair.second << "\n";
}

int main() {
	std::map<char, int> counters_1{}, counters_2{};
	std::string line_1, line_2;
	std::ifstream ifs{"INPUT.TXT"};
	ifs >> line_1 >> line_2;
	ifs.close();
	int len, begin_1=0, begin_2=0;
	bool solved = false;
	for(len = std::min(line_1.size(), line_2.size()); len > 0; --len){
		counters_1.clear();
		counters_2.clear();
		for(begin_1=0; begin_1<len; ++begin_1){
			++counters_1[line_1[begin_1]];
			++counters_2[line_2[begin_1]];
			if(is_equal(counters_1, counters_2)){
				solved = true;
				break;
			}
		}
		for(begin_1=0; begin_1<line_1.size()-len; ++begin_1){
			for(begin_2=0; begin_2<line_2.size()-len; ++begin_2){
				if(is_equal(counters_1, counters_2)){
					solved = true;
					break;
				}else{
					if(begin_2 < line_2.size()-len-1){
						--counters_2[line_2[begin_2]];
						++counters_2[line_2[begin_2+len]];
					}
				}
			}
			if(solved)
				break;
			if(begin_1 < line_1.size()-len-1){
				--counters_1[line_2[begin_2]];
				++counters_1[line_2[begin_2+len]];
			}
			counters_2.clear();
			for(begin_2=0; begin_2<len; ++begin_2)
				++counters_2[line_2[begin_2]];
		}
		if(solved)
			break;
	}
	std::ofstream ofs{"OUTPUT.TXT"};
	if(not solved)
		ofs << 0;
	else{
		ofs << len << "\n" << begin_1+1 << "\t" << begin_2+1;
	}
	return 0;
}
