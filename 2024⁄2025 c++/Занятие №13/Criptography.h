#ifndef CRIPTOGRAPHY_H_
#define CRIPTOGRAPHY_H_

#include <iostream>

std::size_t bit_len(const std::size_t &num){
	std::size_t sum=0;
	for(std::size_t bit=1; bit<(1l<<62); bit<<=1) sum += (bit&num)?1:0;
	return sum;
}

class Key{
private:
	std::size_t N;
public:
	Key(const std::size_t &N):N{N}{}
	std::size_t cur_key(const std::size_t &time)const{
		std::size_t key=N;
		for(std::size_t t=0; t<time; ++t) key += bit_len(key);
		return key;
	}
};

#endif /* CRIPTOGRAPHY_H_ */
