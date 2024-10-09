#include <iostream>
#include "VectorAlgebra.h"

int main() {
	vec_type v1{1.0, 0.0, 0.0}, v2{0.0, 0.0, 1.0};
	std::cout << to_string(v1 + v2) << "\n"
			  << to_string(v1 += {0.0, 1.0, 0.0}) << "\n"
			  << to_string(-v1) << "\n"
			  << abs(v1) << "\n";
	return 0;
}
