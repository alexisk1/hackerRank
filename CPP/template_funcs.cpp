#include <iostream>

template<class T , int t>
T mul(T a){
  return a*t;
}

using namespace std;
int main( ){

    int a;
    cin >>a;
    cout<< mul<int,1>(123);
}
