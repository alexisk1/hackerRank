#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
long ways =0;
void naive_rec_1(int lower, long sum, const long& n,const vector < long >& c){
    // Complete this function
    for(int i = lower; i< c.size(); ++i){
        if(sum+c[i]<n){
           naive_rec_1(i, sum+c[i], n, c);
        }else if(sum+c[i]==n){
            ways++;
        }
    }
}

void naive_rec_2(int lower, long sum, const long& n,const vector < long >& c){
    // Complete this function
    for(int i = lower; i< c.size(); ++i){
        if((n-sum)%c[i]==0){
            ways++;
        }
        if((int)(n-sum)/c[i]>=1){
            int min=c[i];
            for(int x =1 ; x<=(int)(n-sum)/c[i]-1;x++){
                if(sum+x*c[i]<n)naive_rec_2(i+1, sum+x*c[i], n, c);

            }
        }
    }
}

//Naive recursive count 1
long count( long n,const vector < long >& c,int index){
    if(n<0) return 0;
    if(index==0 and n>0) return 0;
    if (n==0) return 1;
    return count(n-c[index-1],c,index)+count(n,c,index-1);
}

long count_memorization( long n,const vector < long >& c){
    long memo[n+1][c.size()] = {};  //Sets to zero instead of memset(memo,0,sizeof(memo));
    for(int i=0;i<c.size();i++) memo[0][i]=1;
  
    for(int n_i=1;n_i<n+1;n_i++){
        for(int m_i=0;m_i<c.size();m_i++){
            if(n_i-c[m_i]>=0)memo[n_i][m_i]+=memo[n_i-c[m_i]][m_i];
            if(m_i>0)memo[n_i][m_i]+=memo[n_i][m_i-1];
        }  
    }
    return memo[n][c.size()-1];
}

long count_lin_memorization( long n,const vector < long >& c){
    int t[n+1] ={};
 
    t[0] = 1;

    for(int i=0; i<c.size(); i++)
        for(int j=c[i]; j<=n; j++)
            t[j] += t[j-c[i]];
    return t[n];
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    sort (c.begin(), c.end()); 
    cout <<  count_lin_memorization(n,c);
    return 0;
}
