#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

long long dp[1001][32][2]; // [time][movements took][under which tree]
int information[1001];
long long infinity=1000000000LL;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int time_len,max_movements;
    cin >> time_len >> max_movements;

    for(int i=1;i<=time_len;i++){
        cin >> information[i];
    }

    dp[0][0][1]=-infinity;
    dp[0][1][0]=-infinity;
    for(int k=1;k<=time_len;k++){
        for(int m=0;m<=max_movements;m++){
            if(information[k]==1){
                
                dp[k][m][0] = max(dp[k][m][0],dp[k-1][m][0]+1);
                dp[k][m][1] = max(dp[k][m][1],dp[k-1][m][1]);
                if(m>=1)
                    dp[k][m][0] = max(dp[k][m][0],dp[k-1][m-1][1]+1);
            }
            else{
                dp[k][m][1] = max(dp[k][m][1],dp[k-1][m][1]+1);
                dp[k][m][0] = max(dp[k][m][0],dp[k-1][m][0]);
                if(m>=1)
                    dp[k][m][1] = max(dp[k-1][m-1][0]+1,dp[k][m][1]);
            }
        }
    }

    int answ=0;
    for(int t=0;t<=1;t++){
        for(int m=0;m<=max_movements;m++){
            if(dp[time_len][m][t]>answ){
                answ=dp[time_len][m][t];
            }
        }
    }

    cout << answ << '\n';

    return 0;
}