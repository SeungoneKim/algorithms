#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int work_info[1500101][2];
int dp[1500101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len;
    cin >> len;

    for(int k=1;k<=len;k++){
        cin >> work_info[k][0] >> work_info[k][1];
    }

    for(int k=1;k<=len;k++){
        
        dp[k+work_info[k][0]] = max(dp[k+work_info[k][0]],dp[k]+work_info[k][1]);
        
        dp[k+1]=max(dp[k],dp[k+1]);
    }
    
    cout << dp[len+1] << '\n';

    return 0;
}