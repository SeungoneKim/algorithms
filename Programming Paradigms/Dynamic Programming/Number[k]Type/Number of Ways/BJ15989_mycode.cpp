#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001];

int main(){

    dp[0]=1;
    for(int k=1;k<=10000;k++){
        dp[k] += dp[k-1];
    }
    for(int k=2;k<=10000;k++){
        dp[k] += dp[k-2];
    }
    for(int k=3;k<=10000;k++){
        dp[k] += dp[k-3];
    }

    int tc;
    cin >> tc;
    while(tc--){
        int query;
        cin >> query;
        cout << dp[query] << '\n';
    }

    return 0;
}