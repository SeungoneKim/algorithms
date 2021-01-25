#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int sequence[1001];
int dp[1001];
int infinity=100000000;

int main(){

    int len;
    cin >> len;

    for(int k=1;k<=len;k++){
        cin >> sequence[k];
    }

    for(int k=1;k<=len;k++){
        dp[k]= infinity;
    }
    dp[1]=0;
    for(int k=1;k<=len;k++){
        for(int t=sequence[k];t>=1;t--){
            dp[k+t] = min(dp[k]+1,dp[k+t]);
        }
    }

    if(dp[len]==infinity){
        cout << -1 << '\n';
    }
    else{
        cout << dp[len] << '\n';
    }

    return 0;
}