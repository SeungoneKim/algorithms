#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int dp[1001][1001];
int dps[1001][1001];
int mod=1000000009;

int main(){

    dp[0][0]=1;
    
    for(int n=1;n<=1000;n++){
        for(int k=1;k<=n;k++){
            dp[n][k] += dp[n-1][k-1];
            dp[n][k] %= mod;
            if(n>=2){
                dp[n][k] += dp[n-2][k-1];
                dp[n][k] %= mod;
            }
            if(n>=3){
                dp[n][k] += dp[n-3][k-1];
                dp[n][k] %= mod;
            }
        }
    }
    for(int n=1;n<=1000;n++){
        for(int k=1;k<=n;k++){
            dps[n][k] = dps[n][k-1]+dp[n][k];
            dps[n][k] %= mod;
        }
    }

    int tc;
    cin >> tc;
    while(tc--){
        int a,b;
        cin >> a >> b;
        cout << dps[a][b] << '\n';
    }


    return 0;
}