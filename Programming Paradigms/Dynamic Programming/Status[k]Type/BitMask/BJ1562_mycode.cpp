#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int dp[101][10][1<<10];
int mod=1000000000;

int main(){

    int n;
    cin >> n;

    for(int k=1;k<=9;k++){
        dp[1][k][1<<k]=1;
    }

    for(int i=1;i<=n-1;i++){
        for(int t=0;t<(1<<10);t++){
            for(int j=0;j<10;j++){
                if(t&(1<<j)){
                    if(j==0){
                        dp[i+1][j+1][t|(1<<(j+1))] += dp[i][j][t];
                        dp[i+1][j+1][t|(1<<(j+1))] %= mod;
                    }
                    else if(j==9){
                        dp[i+1][j-1][t|(1<<(j-1))] += dp[i][j][t];
                        dp[i+1][j-1][t|(1<<(j-1))] %= mod;
                    }
                    else{
                        dp[i+1][j+1][t|(1<<(j+1))] += dp[i][j][t];
                        dp[i+1][j+1][t|(1<<(j+1))] %= mod;
                        dp[i+1][j-1][t|(1<<(j-1))] += dp[i][j][t];
                        dp[i+1][j-1][t|(1<<(j-1))] %= mod;
                    }
                }
            }
        }
    }

    int answ=0;
    for(int k=0;k<=9;k++){
        answ += dp[n][k][(1<<10)-1];
        answ %= mod;
    }

    cout << answ << '\n';

    return 0;
}