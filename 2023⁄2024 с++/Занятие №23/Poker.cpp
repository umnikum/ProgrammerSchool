#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Card.h"
#include "Deck.h"

using namespace std;

int main() {
	vector<Card> hand;
	ifstream ifs{"hand.in"};
	do{
		string card_name;
		ifs >> card_name;
		hand.push_back(Card{card_name});
	}while(!ifs.eof());
	ifs.close();
	int red_count=0, black_count=0;
	for(const Card &card:hand){
		if(Card::is_red(card)){
			++red_count;
		}else{
			++black_count;
		}
		//cout << card.print() << ((Card::is_red(card))? " red" : " black") << "\n";
	}
	cout << "Red: " << red_count << "\nBlack: " << black_count;
}
