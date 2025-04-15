#ifndef CALC_H_
#define CALC_H_

#include <string>
#include <sstream>
#include <vector>


int sign(const char &c){
	switch(c){
	case '+': return 2;
	case '-': return 2;
	case '*': return 3;
	case '/': return 4;
	case '=': return 1;
	default: return 0;
	}
}

int sign(const std::string &c){
	if(c.size() > 1) return 0;
	else return sign(c[0]);
}

int calc(const int &l, const char &op, const int &r){
	switch(op){
	case '+': return l+r;
	case '-': return l-r;
	case '*': return l*r;
	case '/': return l/r;
	case '=': return l == r;
	}
	return 0;
}

std::string translate(const std::string &l, const std::string &op, const std::string &r){
	if(l.compare("ERROR") == 0 or sign(l)>0) return "ERROR";
	if(op.compare("ERROR") == 0 or sign(op)==0) return "ERROR";
	if(r.compare("ERROR") == 0 or sign(r)>0) return "ERROR";
	return std::to_string(calc(std::stoi(l), op[0], std::stoi(r)));
}

std::vector<std::string> calc_split(const std::string &equation){
	std::size_t begin=0, len=0;
	std::vector<std::string> nums{};
	bool is_num = true;
	for(const char &c:equation){
		if(sign(c)){
			if(len>0){
				nums.push_back((is_num)?equation.substr(begin, len):"ERROR");
				nums.push_back(std::string{c});
				begin += len+1;
				len = 0;
				is_num = true;
			}else if(c!='-'){
				nums.push_back(std::string{c});
				++begin;
				is_num = true;
			}else ++len;
		}else{
			++len;
			if(not (std::isdigit(c) or std::isspace(c))) is_num = false;
		}
	}
	nums.push_back((is_num)?equation.substr(begin, len):"ERROR");
	return nums;
}

std::string to_string(const std::vector<std::string> &elements){
	std::stringstream ss;
	for(auto elem:elements) ss << "{" << elem << "}";
	return ss.str();
}

std::string interprate(const std::string &equation){
	std::vector<std::string> elements = calc_split(equation);
	std::size_t begin=0;
	while(elements.size() > 2){
		if(elements.size()>begin+4) if(sign(elements[begin+3])>sign(elements[begin+1])){
			begin+=2;
			continue;
		}
		std::string result = translate(elements[begin],elements[begin+1],elements[begin+2]);
		if(result.compare("ERROR")==0) return result;
		elements.erase(elements.begin()+begin, elements.begin()+begin+3);
		elements.emplace(elements.begin()+begin, result);
		begin=0;
	}
	if(elements.size() != 1) return "ERROR";
	else return elements[0];
}

#endif /* CALC_H_ */
