#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int matrix[501][501];
int dp[501][501];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        memset(dp,-1,sizeof(dp));
        
        int len;
        cin >> len;
        
        for(int k=1;k<=len;k++){
            cin >> matrix[k][k];
        }
        for(int s=1;s<=len;s++){
            for(int e=s;e<=len;e++){
                if(s!=e){
                    matrix[s][e]=matrix[s][e-1]+matrix[e][e];
                }
            }
        }
        
        for(int k=1;k<=len;k++){
            dp[k][k]=0;
        }
        for(int k=1;k<len;k++){
            dp[k][k+1]=matrix[k][k+1];
        }

        for(int k=3;k<=len;k++){
            for(int s=1;s<=len-k+1;s++){
                int e=s+k-1;
                for(int j=s+1;j<=e;j++){
                    if(dp[s][e]==-1 || dp[s][e]>dp[s][j-1]+dp[j][e]+matrix[s][e]){
                        dp[s][e]=dp[s][j-1]+dp[j][e]+matrix[s][e];
                    }
                }
            }
        }
        
        cout << dp[1][len] << '\n';

    }

    return 0;
}