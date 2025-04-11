#ifndef HEX_H_
#define HEX_H_

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

char to_hex(const int &i){
	switch(i){
	case 0:
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
		return '0'+i;
	case 10:
	case 11:
	case 12:
	case 13:
	case 14:
	case 15:
		return 'a'+i-10;
	default:
		return to_hex(i%16);
	}
}

int to_dec(const char &c){
	switch(c){
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
		return c-'0';
	case 'a':
	case 'b':
	case 'c':
	case 'd':
	case 'e':
	case 'f':
		return c-'a'+10;
	default:
		return 0;
	}
}

int bin_len(int64_t i){
	int len=0;
	while(i>0 or i<-1){
		++len;
		i>>=1;
	}
	return len;
}

std::string hex(int64_t i){
	std::stringstream ss;
	do{
		ss << to_hex(i&15);
		i >>= 4;
	}while(i>0 or i<-1);
	std::string num = ss.str();
	num.assign(num.rbegin(), num.rend());
	return num;
}

std::string code_hex(const int64_t &i){
	std::string num = hex(i);
	std::stringstream result;
	int size = num.size(), _1_digit = to_dec(num[0]),
			_1_digit_len = ((bin_len(i)&3) or size<2)?(bin_len(i)&3):4,
			len = ((size>>1)+_1_digit_len<4*(1+(size&1)))?(size-1)>>1:(size+1)>>1;

	if(i<0){
		if(len+_1_digit_len < 4 and size>1 and !(size&1)){
			result << hex(((_1_digit<<4)^(128>>len))|to_dec(num[1])) << num.substr(2);
		}else if(len+_1_digit_len < 8 and (size&1)){
			result << hex((240|_1_digit)^(128>>len)) << num.substr(1);
		}else result << hex(255^(128>>len)) << num;
	}else{
		int _1_bite = 0;
		for(int bit=0; bit<len; _1_bite = _1_bite|(128>>(bit++)));
		if(len+_1_digit_len < 4 and size>1 and !(size&1)){
			_1_bite = _1_bite|(_1_digit<<4)|to_dec(num[1]);
			result << hex(_1_bite) << num.substr(2);
		}else if(len+_1_digit_len < 8 and (size&1)){
			_1_bite = _1_bite|_1_digit;
			if(_1_bite<16 and !len) result << "0";
			result << hex(_1_bite) << num.substr(1);
		}else result << hex(_1_bite) << num;
	}
	return result.str();
}

int64_t decode(const std::string &num){
	int _1_bite = to_dec(num[0])*16 + to_dec(num[1]), len = 0;
	int64_t result;
	for(int bit=128; bit>0 and (_1_bite&bit); bit>>=1) ++len;
	if(len<7){
		result = (_1_bite&(128>>(len+1)))?-1:0;
		if(result<0) _1_bite = _1_bite|(128>>len);
		else for(int bit=0; bit<len;  _1_bite = _1_bite^(128>>bit++));
		result = (result)?_1_bite-256:_1_bite;
	}else result = (to_dec(num[2])&8)?-1:0;
	for(int i_digit=2; i_digit<len*2+2; result = (result<<4)|to_dec(num[i_digit++]));
	return result;
}

void test(const std::vector<int64_t> &nums = {0, 1, 2, 3, 100, 500, 1000000, -1, -100, -500}){
	for(auto num:nums){
		int64_t dnum = decode(code_hex(num));
		if(num != dnum) {
			std::cout << num << "(" << hex(num) << ")\t" << code_hex(num) << "\t" << dnum << "\n";
		}
	}
}

void test(const int64_t &range){
	for(int64_t num=0; num<range; ++num){
		int64_t dnum = decode(code_hex(num));
		if(num != dnum) {
			std::cout << num << "(" << hex(num) << ")\t" << code_hex(num) << "\t" << dnum << "\n";
		}
		dnum = decode(code_hex(-num));
		if(-num != dnum){
			std::cout << -num << "(" << hex(-num) << ")\t" << code_hex(-num) << "\t" << dnum << "\n";
		}
	}
}

#endif /* HEX_H_ */
