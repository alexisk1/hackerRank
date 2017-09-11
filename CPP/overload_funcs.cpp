
#include <iostream>
using namespace std;
int res(int a , int b=2);
int res(double a, int b=10);

int main(){
    int a=10;
    int b=20;
    cout<<res(a)<<"\n";
    cout<<res(a,b)<<"\n";
    cout<<res(double(a),b)<<"\n";
    cout <<res(double(a))<<"\n";
    return 0;
}

int res(int c, int d){
    return c+d+10;
};
int res(double e, int f){
    return e*f;
};
