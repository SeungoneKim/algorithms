#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

long long dp[1000001];
long long mod = 1000000000LL;

int main(){

    int n;
    cin >> n;

    dp[1]=0; dp[2]=1; dp[3]=2;
    for(int k=4;k<=n;k++){
        dp[k] += (k-1)*dp[k-1];
        dp[k] %= mod;
        dp[k] += (k-1)*dp[k-2];
        dp[k] %= mod;
    }

    cout << dp[n] << '\n';

    return 0;
}