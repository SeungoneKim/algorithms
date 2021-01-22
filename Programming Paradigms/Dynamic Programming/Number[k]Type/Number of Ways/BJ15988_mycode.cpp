#include <iostream>

using namespace std;

long long dp[1000001];
int mod = 1000000009;

int main(){
    int tc;
    cin >> tc;

    dp[1]=1; dp[2]=2; dp[3]=4;
    for(int k=4;k<=1000001;k++){
        dp[k] = (dp[k-1]+dp[k-2]+dp[k-3])%mod;
    }

    int a=0;
    while(tc--){
        cin >> a;
        cout << dp[a] << '\n';
    }

    return 0;
}