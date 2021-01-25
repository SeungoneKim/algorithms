#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

int n,m,p;
long long mod=1000000007;
long long dp[101][101];

long long go(int len,int x){
    int y=n-x;
    if(len==p){
        if(y==0) return 1;
        else return 0;
    }
    long long& answ= dp[len][x];
    if(answ!=-1) return answ;

    answ=0;
    if(y>=0){
        answ += go(len+1,x+1)*y;
    }
    if(x>m){
        answ += go(len+1,x)*(x-m);
    }
    answ %= mod;
    return answ;
}

int main(){

    cin >> n >> m >> p;

    memset(dp,-1,sizeof(dp));
    cout << go(0,0) << '\n';

    return 0;
}