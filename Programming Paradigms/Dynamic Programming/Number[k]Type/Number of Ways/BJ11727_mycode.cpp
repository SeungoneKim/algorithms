#include <iostream>

using namespace std;

int dp[1001];

int main(){
    int n;
    cin >> n;

    dp[1]=1;
    dp[2]=3;
    for(int k=3;k<=n;k++){
        dp[k] = (dp[k-1]+ (2*dp[k-2])%10007)%10007;
    }

    cout << dp[n] << '\n';

    return 0;
}