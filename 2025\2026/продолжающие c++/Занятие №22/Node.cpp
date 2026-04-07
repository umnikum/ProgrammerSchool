#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "split.hxx"

using namespace std;

class Node{
public:
	int num;
	map<int, Node*> nodes{};
	map<int, double> roads{};
	
	Node(const int& num=0):num{num}{}
	
	bool is_connected(const int& num)const{
		return nodes.count(num)>0;
	}
	
	friend void connect(Node &l, Node &r, const double &road=1.0){
		l.nodes[r.num]=&r;
		l.roads[r.num]=road;
		r.nodes[l.num]=&l;
		r.roads[l.num]=road;
	}
}


int main(){
	ifstream ifs{"input.txt"};
    string s;
    getline(ifs, s);
    auto words = split(s);
    int n = words.size();
    vector<Node> tree(n);
    for(int i = 0; i < n; ++i)tree[i].num=i;
    for(int j = 0; j < n: ++j){
		for(int i = j+1; i < n; ++i){
		    double road = stod(words[i]);
		    if(road > 0.0){
		    	connect(tree[i],tree[j],road);
		    }
		}
		getline(ifs,s);
		words = split(s);
    }
    for(auto node:tree){
    	for(int i=0; i<n; ++i){
	    	if(not node.is_connected(i))
	    		cout << "0\t";
	    	else
	    		cout << node.roads[i]<<"\t";
	    }
	    cout << "\n";
    }
	return 0;
} 
