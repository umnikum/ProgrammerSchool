#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;


vector <string> split (const string &s){
   int start = 0;
   int length = 0;
   vector <string> ans;
 for (int i = 0;i < s.size() - 1; ++ i){
     if((s[i] ==' ')&& (s[i + 1] != ' ')){
      start = i + 1;
     }else if ((s[i] == ' ') && (s[i + 1] == ' ')){
        start ++;
     }else if ((s[i] != ' ' ) && (s[i + 1] == ' ')){
         length = (i + 1) - start;
         ans.push_back(s.substr(start, length));
        start = i;
     }
 }
 if(start < s.size())
  ans.push_back (s.substr(start, s.size() - start));
 return ans;
}

class Bt{
public:
    int *arr;
    int n = 0;
    vector <int> v;

Bt (string filename){
        ifstream ifs{filename};
    string s;
    getline( ifs, s);
    int j = 1;
    auto words = split(s);
    arr = new int[words.size() * words.size()];
    for (int i =0; i < words.size(); ++i){
        arr[i] = stoi(words[i]);
        n ++;
    }
        do{
    getline( ifs, s);
    if (s.empty())
        break;
    else
        words = split(s);
    for (int i =0; i < words.size(); ++i){
        arr[j * n + i] = stoi(words[i]);
    }j ++;
    }while(!ifs.eof());
}
~Bt(){
    delete [] arr;
}

int step(int &b){
    int c = v.back();
    if (arr[c * n + b] == 0){
        for(int i = 0; i < n; ++ i){
            if (arr[c * n + i] != 0){
                bool est = false;
                for (auto e: v){
                if (e == i) {
                     est = true;
                     break;
                }
                }
                if(!est){
                v.push_back(i);
                int l = step(b);
                v.pop_back();
                c = v.back();
                if (l != 0){
                    return l + arr[c * n + i] ;
                }
                }
        }
    }
    }else {
        return arr[c * n + b];
    }
}
    friend string to_string(Bt bt){
        stringstream ss;
        for(int i=0; i<bt.n;++i){
            for(int j=0; j<bt.n;++j)
                ss << bt.arr[i*bt.n+j]<<" ";
            ss <<"\n";
        }
        return ss.str();
    }
};

int main()
{

    Bt put {"Input.txt"};
    int a, b;
    cin >> a >> b;
    put.v.push_back(a);
    cout<< put.step(b);
}
