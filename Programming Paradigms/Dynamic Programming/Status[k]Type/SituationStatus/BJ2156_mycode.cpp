#include <iostream>
#include <algorithm>

using namespace std;

int dp[10001][3]; // dp[kth number][how many have you drank]
int amount[10001];

int main(){
    int grapenum;
    cin >> grapenum;
    
    for(int k=1;k<=grapenum;k++){
        cin >> amount[k];
    }
    
    dp[1][0]=0;
    dp[1][1]=amount[1];
    dp[1][2]=0;
    
    for(int k=2;k<=grapenum;k++){
        dp[k][0] = max(max(dp[k-1][0],dp[k-1][1]),dp[k-1][2]);
        dp[k][1] = dp[k-1][0] + amount[k];
        dp[k][2] = dp[k-1][1] + amount[k];
    }
    
    int answ = max(max(dp[grapenum][0],dp[grapenum][1]),dp[grapenum][2]);
    cout << answ;
    
    return 0;
}