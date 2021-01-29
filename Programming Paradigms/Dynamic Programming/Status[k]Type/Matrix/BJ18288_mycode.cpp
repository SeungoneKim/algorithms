#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int n,k;
long long dp[100000][10][2][2];
long long mod = 1000000007LL;

long long go(int idx,int a,int b,int c){
    if(idx==n){
        if(a==0 && c>=1) return 1;
        else return 0;
    }

    long long& answ=dp[idx][a][b][c];
    if(answ!=-1) return answ;
    answ=0;

    // when we choose a
    if(k>0) answ += go(idx+1,(a+1)%k,0,c);
    answ %= mod;
    // when we choose b
    if(b!=1) answ += go(idx+1,a,1,c);
    answ %= mod;
    // when we choose c
    answ += go(idx+1,a,0,1);
    answ %= mod;
    
    return answ;
}

int main(){

    cin >> n >> k;

    memset(dp,-1,sizeof(dp));

    cout << go(0,0,0,0) << '\n';

    return 0;
}