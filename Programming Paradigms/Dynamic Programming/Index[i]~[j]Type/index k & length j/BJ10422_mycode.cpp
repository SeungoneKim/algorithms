#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long dp[5001];

int main(){

    dp[0]=1;
    dp[2]=1;
    for(int k=4;k<=5000;k+=2){
        for(int j=2;j<=k;j+=2){
            dp[k] += dp[j-2]*dp[k-j];
            dp[k] %= 1000000007;
        }
    }

    int tc;
    cin >> tc;
    while(tc--){
        int a;
        cin >> a;

        cout << dp[a]%1000000007 << '\n';
    }

    return 0;
}