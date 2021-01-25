#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

long long dp[101][101][101];
int mod=1000000007;

int main(){

    int n,l,r;
    cin >> n >> l >> r;

    dp[1][1][1]=1;
    for(int k=2;k<=n;k++){
        for(int t=1;t<=l;t++){
            for(int i=1;i<=r;i++){
                dp[k][t][i] += dp[k-1][t-1][i]%mod;
                dp[k][t][i] += dp[k-1][t][i-1]%mod;
                dp[k][t][i] += (dp[k-1][t][i] * (k-2))%mod;
                dp[k][t][i] %= mod;
            }
        }
    }

    cout << dp[n][l][r] << '\n';

    return 0;
}