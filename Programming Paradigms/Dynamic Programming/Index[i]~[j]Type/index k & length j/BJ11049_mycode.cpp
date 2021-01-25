#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int matrix_list[501][2];
long long dp[501][501];

int main(){

    int matrix_num;
    cin >> matrix_num;
    for(int k=1;k<=matrix_num;k++){
        cin >> matrix_list[k][0] >> matrix_list[k][1];
    }

    memset(dp,-1,sizeof(dp));
    for(int k=1;k<=matrix_num;k++){
        dp[k][k]=0;
    }

    for(int k=2;k<=matrix_num;k++){
        for(int s=1;s<=matrix_num-k+1;s++){
            int e=s+k-1;
            for(int j=s;j<e;j++){
                if(dp[s][e]==-1 || dp[s][e]>dp[s][j]+dp[j+1][e]+matrix_list[s][0]*matrix_list[j][1]*matrix_list[e][1]){
                    dp[s][e] = dp[s][j]+dp[j+1][e]+matrix_list[s][0]*matrix_list[j][1]*matrix_list[e][1];
                }
            }
        }
    }

    cout << dp[1][matrix_num] << '\n';

    return 0;
}