#ifndef DECK_H_
#define DECK_H_

#include <iostream>
#include <vector>
#include <random>
#include "Card.h"

using namespace std;

class Deck{
public:
	vector<Card> cards{};
	Deck(){
		for(int suit=0; suit<4; ++suit)
			for(int value=2; value<15; ++value)
				cards.push_back(Card{suit, value});
	}
	void shuffle(){
		int size = cards.size();
		mt19937 gen{random_device{}()};
		uniform_int_distribution<int> dist{0, size-1};
		for(int i=0; i<1000; ++i){
			int from{dist(gen)}, to;
			do{
				to = dist(gen);
			}while(to == from);
			swap(cards[from], cards[to]);
		}
	}
};


#endif /* DECK_H_ */
