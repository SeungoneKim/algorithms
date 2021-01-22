#include <iostream>

using namespace std;

int dp[100001];

int main(){

    int n;
    cin >> n;

    dp[1]=1;
    for(int k=2;k<=n;k++){
        for(int t=1;t*t<=k;t++){
            if(dp[k]==0)
                dp[k] = dp[k-1]+1;
            else{
                dp[k] = min(dp[k-t*t]+1,dp[k]);
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}