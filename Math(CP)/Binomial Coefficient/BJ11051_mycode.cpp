#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int dp[1001][1001];
int mod=10007;

int main(){

    int n,m;
    cin >> n >> m;

    dp[1][1]=1;
    for(int k=1;k<=n;k++){
        dp[k][0]=1;
    }
    for(int k=2;k<=n;k++){
        for(int t=1;t<=n;t++){
            dp[k][t] = (dp[k-1][t-1]+dp[k-1][t])%mod;
        }
    }

    cout << dp[n][m] << '\n';

    return 0;
}