#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int dp[11][1<<11];

int main(){

    int rownum,colnum;
    cin >> rownum >> colnum;

    vector<string> matrix(rownum+1);
    for (int i=1; i<=rownum; i++) {
        cin >> matrix[i];
    }

    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    for(int r=1;r<=rownum;r++){
        for(int prev=0;prev<(1<<colnum);prev++){
            if(dp[r-1][prev]==-1) continue;
            for(int cur=0;cur<(1<<colnum);cur++){
                int cnt=0;
                int last=-100;
                for(int k=0;k<colnum;k++){
                    if(matrix[r][k]=='#') continue;
                    // horizontal -> vertical
                    if(cur&(1<<k)){
                        if(r-1==0) cnt++;
                        else if((prev&(1<<k))==0) cnt++;
                        else if(matrix[r-1][k]=='#') cnt++;
                    }
                    else{
                        if(last+1 != k){
                            cnt++;
                        }
                        last=k;
                    }
                }
                if(dp[r][cur]==-1 || dp[r][cur]>dp[r-1][prev]+cnt){
                    dp[r][cur] = dp[r-1][prev]+cnt;
                }
            }
        }
    }
    int answ=-1;
    for(int i=0;i<(1<<colnum);i++){
        if(dp[rownum][i]==-1) continue;
        if(answ==-1 || answ>dp[rownum][i]){
            answ=dp[rownum][i];
        }
    }
    cout << answ << '\n';

    return 0;
}