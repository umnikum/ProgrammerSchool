#include <iostream>
#include <random>

using namespace std;

float dps_formula_simple(const float &damage, const float &crit_chance, const float &crit_damage){
	return damage * (1.0 + crit_chance*crit_damage);}

float dps_formula_simple(const float &damage, const float & as, const float &crit_chance, const float &crit_damage){
	return damage * as * (1.0 + crit_chance*crit_damage);}

int main() {
	float damage, crit_chance, crit_damage;
//32 0.3 0.6
	cin >> damage >> crit_chance >> crit_damage;
	float dps{dps_formula_simple(damage, crit_chance, crit_damage)};
	cout << "DPS approximation: " << dps << endl;


	mt19937 gen{random_device{}()};
	uniform_real_distribution<float> dist{0.0, 1.0};
	int crit_counter{0}, amount{1000};
	float total_damage{0};
	for(int i=0; i<amount; ++i){
		total_damage += damage;
		float p{dist(gen)};
		if(p <= crit_chance){
			++crit_counter;
			total_damage += damage * crit_damage;
		}
	}

	cout << "In " << amount << " hits damage dealt: " << total_damage << " critical hits registered: " << crit_counter
			<< "\nCalculted damage: " << amount * dps << " critical hits expected: " << static_cast<int>(amount*crit_chance);

	return 0;
}
