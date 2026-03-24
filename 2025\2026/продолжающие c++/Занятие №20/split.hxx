#ifndef SPLIT_HXX_
#define SPLIT_HXX_

#include <string>
#include <vector>


std::vector<std::string> split(const std::string &line, const char &delimiter=' '){
	std::vector<std::string> words{};
	bool in_word=false; std::size_t start = 0;
	for(std::size_t i=0l; i<line.size(); ++i){
		if(not in_word){
			start = i;
			if(line[i] != delimiter){
				in_word = true;
			}
		}else{
			if(line[i] == delimiter){
				words.push_back(line.substr(start, i-start));
				start = i;
				in_word = false;
			}
		}
	}
	words.push_back(line.substr(start, line.size()-start));
	return words;
}

#endif /* SPLIT_HXX_ */ 
