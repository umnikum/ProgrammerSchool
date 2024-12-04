#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <map>

template <class Container = int>
class Repository{
private:
	int next_index{0};
	std::map<int, Container> data{};

	Repository(){};
	Repository(Repository<Container> const&) = delete;
	void operator=(Repository<Container> const&) = delete;
public:
	static Repository<Container>& get_instance(){
		static Repository<Container> instance{};
		return instance;
	}
	Container& get(const int &index){
		return data.at(index);
	}
	void add(const Container &value){
		data[++next_index] = value;
	}
};


#endif /* REPOSITORY_H_ */
