#include <bits/stdc++.h>
#include <fstream>
#include <vector>
using namespace std;

long long find_next(const long long & n,  bool * library){
  //  cout<<"next!!\n";
    for(long long i=0;i<n; i++)if(library[i]==false) return i;
    return -1;
}

long long traverse(long long  n,long long c,vector<int>* adj,bool * library){
    library[c]=true;
  /*  cout<<"\n";
    for (int i=0; i<n;i++) cout<<library[i]<<" "; cout<<"!!library\n";*/
    long long nums=0;
    //cout<<"traverse!!"<<c<<"!!!\n";
    for (long long i=0; i<adj[c].size(); i++){
        if(library[adj[c][i]]==false){
             nums+=traverse(n,adj[c][i],adj,library);
        }
    }
    return 1+nums;
}
int main() {
   ifstream fin;
 fin.open("input");
    long q;
    fin >> q;
    for(int a0 = 0; a0 < q; a0++){
        long long n;
        long long m;
        long long x;
        long long y;
        fin >> n >> m >> x >> y;
       // cout<<n<<" "<<m<<"\n";
        if(x<=y){ 
           cout<<n*x<<"\n";
           long c,d;
           for(long i=0;i<m;i++ )fin>>c>>d;
           continue;
        }
        bool library[n];
        for(long long i=0;i<n;i++)library[i]=false;
       // cout<<"1SPACE CREATED!!"<<n<<" \n";
        vector<int> adj[n];
      //  for(long long  x=0;x<n;x++)for(long long y=0;y<n;y++)adj[n*x+y]=false;
     //   cout<<"SPACE CREATED!! \n";
        for(long long a1 = 0; a1 < m; a1++){
     //       cout<<"!!!"<<a1<<"\n";
            int city_1;
            int city_2;
            fin >> city_1 >> city_2;
            city_1--; city_2--;
       //     cout<<"D:"<<city_1<<" "<<city_2<<"\n";
            adj[city_1].push_back(city_2);
        //    cout<<"D:"<<city_1<<" "<<city_2<<"\n";
            adj[city_2].push_back(city_1);
        //    cout<<"D:"<<city_1<<" "<<city_2<<"\n";
        //    cout<<"!!!"<<a1<<"\n";
        }
     //   cout<<"Input cinished!! \n";
        long long cost=0;
        long long c=find_next(n,library);;
      //  cout<<"entered\n";
     //   cout<<"entered\n";
        do {

            long long non=traverse(n,c,adj,library);
           // cout<<non<<"  !"<<"\n";
            if(non>1)cost+=x+y*(non-1);
            else cost+=x;
            c=find_next(n,library);
      //      cout<<c<<" "<<"\n";
   //  cout<<"\n";
    //for (int i=0; i<n;i++) cout<<library[i]<<" "; cout<<"!!library\n";
        }while(c>0);
        cout<<cost<<"\n";
        
    }
    return 0;
}

