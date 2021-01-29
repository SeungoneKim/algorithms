#include <iostream>

using namespace std;

int dp[31];

int main(){
    int n;
    cin >> n;

    dp[0]=1; dp[2]=3;
    for(int k=4;k<=n;k+=2){
        dp[k] = dp[k-2]*3;
        for(int t=0;t<=k-4;t+=2){
            dp[k] += dp[t]*2;
        }
    }

    cout << dp[n] << '\n';

    return 0;
}