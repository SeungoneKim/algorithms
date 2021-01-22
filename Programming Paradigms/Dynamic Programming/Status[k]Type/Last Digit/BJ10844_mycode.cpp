#include <iostream>

using namespace std;

int dp[100][11]; // dp[digit number][last digit]
// dp[k][10] = dp[k][0]+dp[k][1]+ ... + dp[k][9]
int mod = 1000000000;

int main(){
    int num;
    cin >> num;

    for(int t=1;t<=9;t++){
        dp[1][t] =1;
    }
    dp[1][10] = 9;

    for(int k=2;k<=num;k++){
        dp[k][0] = dp[k-1][1];
        dp[k][9] = dp[k-1][8];
        for(int t=1;t<=8;t++){
            dp[k][t] += (dp[k-1][t-1]+dp[k-1][t+1])%mod;
        }
        for(int t=0;t<=9;t++){
            dp[k][10] += dp[k][t];
            dp[k][10] %= mod;
        }
    }

    cout << dp[num][10] << '\n';

    return 0;
}