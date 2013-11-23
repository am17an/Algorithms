#define DEBUG 1
#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;
#ifdef DEBUG
class Debugger{
  public: 
  Debugger(){}

  template<typename T>
  Debugger operator,(const T & a) const{
    cout << a << endl;
    return *this;
  }

  template<typename K>
  Debugger operator,(const vector<K> & v) const{
    cout <<"vector " << endl;
    for(int i = 0 ; i < v.size() ; ++i)
      cout << v[i] << " " ;
    cout << endl;
    return *this;
  }
  
  template<typename K,typename V>
  Debugger operator,(const map<K,V> & v) const{
    cout << "map" << endl;
    for(typeof(v.begin()) it = v.begin() ; it!=v.end() ; ++it){
      *this,it->first;
      *this,it->second;
    }
    return *this;
  }
  
  ~Debugger(){

  }
};
#else
class Debugger{
  public:
    Debugger(){}

  template<typename T>
  Debugger operator,(const T & a) const{
      // suck it up
      return *this;
  }

  ~Debugger(){

  }
};
#endif

int main(){
  Debugger d;
  d,1,2,3,4;
}
