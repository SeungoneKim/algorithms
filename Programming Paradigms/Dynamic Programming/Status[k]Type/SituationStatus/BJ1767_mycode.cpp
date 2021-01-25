#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>

using namespace std;

long long dp[101][101][101];
long long go(int n,int m,int k){
    if(k==0){
        return 1;
    }
    if(n<=0 || m<=0 || k<0){
        return 0;
    }
    long long& answ=dp[n][m][k];
    if(answ!=-1){
        return answ;
    }
    answ=0;
    answ = go(n-1,m,k) + go(n-1,m-1,k-1)*m + go(n-1,m-2,k-2)*m*(m-1)/2 + go(n-2,m-1,k-2)*m*(n-1);
    answ %= 1000001;

    return answ;
}

int main(){

    int n,m,k;
    cin >> n >> m >> k;
    memset(dp,-1,sizeof(dp));

    cout << go(n,m,k) << '\n';

    return 0;
}