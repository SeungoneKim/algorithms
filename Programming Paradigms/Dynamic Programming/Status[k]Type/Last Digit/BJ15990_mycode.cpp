#include <iostream>

using namespace std;

long long dp[100001][4]; // [total sum][last digit number]
// dp[k][0] = (dp[k][1] + dp[k][2] + dp[k][3]) % mod
int mod = 1000000009;

int main(){
    int tc;
    cin >> tc;

    dp[1][1]=1; dp[1][0]=1;
    dp[2][2]=1; dp[2][0]=1;
    dp[3][1]=1; dp[3][2]=1; dp[3][3]=1; dp[3][0]=3;

    for(int k=4;k<=100000;k++){
        dp[k][1] = (dp[k-1][2]+dp[k-1][3])%mod;
        dp[k][2] = (dp[k-2][1]+dp[k-2][3])%mod;
        dp[k][3] = (dp[k-3][1]+dp[k-3][2])%mod;
        dp[k][0] = (((dp[k][1]+dp[k][2])%mod)+dp[k][3])%mod;
    }

    while(tc--){
        int target;
        cin >> target;

        long long asw = dp[target][0];

        cout << asw << '\n';
    }

    return 0;
}