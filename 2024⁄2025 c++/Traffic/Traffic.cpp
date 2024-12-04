#include <iostream>
#include "Road.h"
#include "Repository.h"

int main() {
	Repository<Road>::get_instance().add(Road{0, 1, 10.0});
	std::cout << to_string(Repository<Road>::get_instance().get(1)) << "\n";

	Repository<Road> *repo = &Repository<Road>::get_instance();
	repo->add(Road{1, 2, 5.0});
	std::cout << to_string(Repository<Road>::get_instance().get(2)) << "\n";

	Repository<Road>::get_instance().add(Road{2, 3, 5.0});
	std::cout << to_string(repo->get(3)) << "\n";
	return 0;
}
