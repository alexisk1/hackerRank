#include <bits/stdc++.h>
#include <vector>
using namespace std;

long long  find_next(long long  n,long long c , bool * visited, vector<long long > * adj){
    for(long long  i =c; i<n;i++){
        if(visited[i]==false)return i;
    }
    return -1;
}
long long  traverse(long long  c , bool * visited,vector<long long > * adj){
    long long  res=0;
    visited[c]=true;
    for(long long  i=0; i<adj[c].size();i++){
        if(visited[adj[c][i]]==false)res+=traverse(adj[c][i] , visited,adj);
    }
    return 1+res;
}
int main() {
    long long  q;
    cin >> q;
    for(long long  a0 = 0; a0 < q; a0++){
        long long  n;
        long long  m;
        long long  x;
        long long  y;
        cin >> n >> m >> x >> y;
        if(x<y){
            cout<<n*x<<"\n";
            long long  a; 
            long long  b;
            for(long long  i=0; i<m;i++) cin>>a>>b;
            continue;
        }
        vector<long long > adj[n];
        bool visited[n] = {};
        for(long long  i=0;i<n;i++)visited[n]=false;
        for(long long a1 = 0; a1 < m; a1++){
            long long city_1;
            long long city_2;
            cin >> city_1 >> city_2;
            adj[city_1-1].push_back(city_2-1);
            adj[city_2-1].push_back(city_1-1);

        }
        long long c=find_next(n,0,visited,adj);
        long long cost=0;
        while(c>=0){
            long long tra=traverse(c,visited,adj);
            if(tra>1) cost+=x+(tra-1)*y;
            else cost+=x;
            c=find_next(n,c,visited,adj);
        }
        cout<<cost<<"\n";
    }
    return 0;
}
