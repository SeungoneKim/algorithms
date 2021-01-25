#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dp[101];

int main(){

    int len;
    cin >> len;

    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=3;
    for(int k=4;k<=len;k++){
        dp[k]=dp[k-1]+1;
        for(int j=1;j<=k-3;j++){
            dp[k]=max(dp[k],dp[j]*(k-j-1));
        }
    }

    cout << dp[len] << '\n';

    return 0;
}