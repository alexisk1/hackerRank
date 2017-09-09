#include <bits/stdc++.h>

using namespace std;

long long count(int i, const vector <int> & arr ){
    long long res = 0;
    if(1==arr[i]) return res;

    for(int x=i;x<arr.size()-1;x++)
        if(arr[x]==arr[i]) res++;
         else return res;
    return res;
}
long long candies(int n, vector <int> arr) {
    // Complete this function
   long long result = arr.size();
    for(long i=0 ; i < arr.size()-1; i++) 
        if(arr[i]<arr[i+1])arr[i]=2;
        else if (arr[i]==arr[i+1])arr[i]=1;
        else arr[i]=0;
    arr[arr.size()-1]=1;
    //for(auto d: arr) cout<<d<<" "; cout<<"\n";
    long long prev_c = 0; // 
    long long prev_d = 0; // 0 down 2 up
    for(long long i=0; i<arr.size()-1;i++){
        long long x = count(i,arr);

     //  cout<<i<<" "<<x<<" \n";
       if(x!=0){
        if(prev_c < x && prev_d==2 && arr[i]==0){
            result-= prev_c*(prev_c+1)/2;
            result+= prev_c*(prev_c-1)/2;
        }
        long long next_i=0;

       if(prev_c >= x && prev_d==2 && arr[i]==0){
            x--;
            next_i=i+x;
        }else{
           next_i=i+x-1;
       }
        prev_c = x;
        prev_d =arr[i];
        
        result+= x*(x+1)/2;
           i= next_i;
       }
    }
    return result;
}
long long candies_2(int n, vector <int> arr) {
    // Complete this function
   long long result = 0;
   long long up[arr.size()] = {};
   long long down[arr.size()] = {};
    up[0]=1;
    for(long long i=1 ; i < arr.size();i++) up[i]= (arr[i]>arr[i-1]? up[i-1]+1: 1);
    down[arr.size()-1]=1;
    for(long long i=arr.size()-2 ; i < arr.size();i--) down[i]= (arr[i]>arr[i+1]? down[i+1]+1: 1);
 //   for(auto d: up) cout<<d<<" "; cout<<"\n";
    
 //   for(auto d: down) cout<<d<<" "; cout<<"\n";

    for(long long i=0 ; i < arr.size();i++) result+=(up[i]>down[i]? up[i]: down[i] );

    return result;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    long long result = candies_2(n, arr);
    cout << result << endl;
    return 0;
}


