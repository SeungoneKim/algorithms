#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

long long dp[61][31];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[60][30]=1;
    for(int t=29;t>=0;t--){
        for(int k=59;k>=0;k--){
            int half=k-(2*t);
            if(half<0) continue;
            dp[k][t] += dp[k+1][t+1];
            dp[k][t] += dp[k+1][t];
        }
    }
    
    int b=0;
    while(cin >> b){
        if(b==0){
            break;
        }
        cout << dp[60-2*b][30-b] << '\n';
    }


    return 0;
}