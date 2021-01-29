#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int dp[31][8];

int main(){

    int n;
    cin >> n;

    dp[1][0]=1; dp[1][3]=1; dp[1][6]=1;
    for(int k=2;k<=n;k++){
        for(int t=0;t<=7;t++){
            dp[k][t] += dp[k-1][7-t];
        }
        dp[k][3] += dp[k-1][7];
        dp[k][6] += dp[k-1][7];
        dp[k][7] += dp[k-1][3];
        dp[k][7] += dp[k-1][6];
    }

    cout << dp[n][7] << '\n';

    return 0;
}