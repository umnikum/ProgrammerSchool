#include <iostream>
#include <string>
#include <map>
#include <fstream>

int diff(const std::map<char, int> &counters){
	int sum = 0;
	for(auto pair:counters)
		sum += std::abs(pair.second);
	return sum/2;
}

void print(const std::map<char, int> &counters){
	for(auto pair:counters)
		std::cout << pair.first << ": " << pair.second << "\n";
}

void clone(const std::map<char, int> &counters_1, std::map<char, int> &counters_2){
	counters_2.clear();
	for(auto pair:counters_1)
		counters_2[pair.first] = pair.second;
}

class Calc{
private:
	std::map<char, int> counters{}, counters_step_mem{}, counters_start_mem{};
	std::string line_1, line_2;
	std::size_t len, begin_1=0, begin_2=0;

	bool move_substr_1(const std::size_t &steps){
		if(begin_1 >= line_1.size()-len)
			return false;
		//std::cout << "Moving first substring: " << begin_2 << " for: ";
		for(std::size_t i=0; i<steps; ++i){
			if(begin_1 < line_1.size()-len){
				--counters[line_1[begin_1]];
				++counters[line_1[begin_1+len]];
			}else {
				//std::cout << i << " steps\n";
				return false;
			}
			++begin_1;
		}
		//std::cout << steps << "steps\n";
		return true;
	}

	bool move_substr_2(const std::size_t &steps){
		if(begin_2 >= line_2.size()-len)
			return false;
		//std::cout << "Moving second substring: " << begin_2 << " for: ";
		for(std::size_t i=0; i<steps; ++i){
			if(begin_2 < line_2.size()-len){
				++counters[line_2[begin_2]];
				--counters[line_2[begin_2+len]];
			}else {
				//std::cout << i << " steps\n";
				return true;
			}
			++begin_2;
		}
		//std::cout << steps << "steps\n";
		return true;
	}

	bool reduce_len(const std::size_t &amount){
		//std:: cout << "Reducing checked length from: " << len;
		for(std::size_t i=0; i<amount and len>0; ++i){
			--counters[line_1[len-1]];
			++counters[line_2[len-1]];
			--len;
		}
		//std::cout << " -> " << len << "\n";
		return len > 0;
	}
public:
	Calc(){
		std::ifstream ifs{"INPUT.TXT"};
		ifs >> line_1 >> line_2;
		len = std::min(line_1.size(), line_2.size());
		for(begin_1=0; begin_1<len; ++begin_1){
			++counters[line_1[begin_1]];
			--counters[line_2[begin_1]];
		}
		begin_1 = 0;
	}
	void submit_answer(const bool &solved)const{
		std::ofstream ofs{"OUTPUT.TXT"};
		if(solved)
			ofs << len << "\n" << begin_1+1 << "\t" << begin_2+1;
		else
			ofs << 0;
	}
	bool solve(){
		std::size_t cur_diff=0, min_diff=len, total_min_diff=min_diff;
		len = std::min(line_1.size(), line_2.size());
		do{
			clone(counters, counters_start_mem);
			total_min_diff = len;
			begin_1 = 0;
			do{
				min_diff = len;
				clone(counters, counters_step_mem);
				begin_2 = 0;
				do{
					cur_diff = diff(counters);
					min_diff = std::min(min_diff, cur_diff);
					if(cur_diff == 0){
						return true;
					}
				}while(move_substr_2(min_diff));
				clone(counters_step_mem, counters);
				total_min_diff = std::min(total_min_diff, min_diff);
			}while(move_substr_1(total_min_diff));
			clone(counters_start_mem, counters);
		}while(reduce_len(((total_min_diff > 1)?total_min_diff:1)));
		return false;
	}
};

int main() {
	Calc calc{};
	calc.submit_answer(calc.solve());
	return 0;
}
