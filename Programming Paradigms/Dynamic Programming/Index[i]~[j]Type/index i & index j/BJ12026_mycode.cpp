#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int dp[1001];

int main(){

    int len;
    cin >> len;

    string s;
    cin >> s;

    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int k=0;k<len;k++){
        for(int t=k+1;t<len;t++){
            if(s[k]=='B' && s[t]=='O'){
                if(dp[k]!=-1){
                    if(dp[t]==-1 || (dp[t]!=-1 && dp[t]>dp[k]+(t-k)*(t-k))){
                        // cout << "case1 :" << k << ' ' << t << '\n';
                        dp[t]=dp[k]+(t-k)*(t-k);
                    }
                }
            }
            else if(s[k]=='O' && s[t]=='J'){
                if(dp[k]!=-1){
                    if(dp[t]==-1 || (dp[t]!=-1 && dp[t]>dp[k]+(t-k)*(t-k))){
                        // cout << "case2 :" << k << ' ' << t << '\n';
                        dp[t]=dp[k]+(t-k)*(t-k);
                    }
                }
            }
            else if(s[k]=='J' && s[t]=='B'){
                if(dp[k]!=-1){
                    if(dp[t]==-1 || (dp[t]!=-1 && dp[t]>dp[k]+(t-k)*(t-k))){
                        // cout << "case3 :" << k << ' ' << t << '\n';
                        dp[t]=dp[k]+(t-k)*(t-k);
                    }
                }
            }
        }
    }

    cout << dp[len-1] << '\n';


    return 0;
}