#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int dp[(1<<17)][17];
int matrix[17][17];
int infinity=100000000;

int main(){

    int n;
    cin >> n;

    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            cin >> matrix[r][c];
        }
    }

    for(int k=0;k<n;k++){
        for(int t=0;t<(1<<n);t++){
            dp[t][k]=infinity;
        }
    }

    dp[1][0]=0;
    for(int k=0;k<(1<<n);k++){
        for(int t=0;t<n;t++){
            if(k&(1<<t)){
                for(int j=0;j<n;j++){
                    if(t==j) continue;
                    if(k&(1<<j) && matrix[j][t]!=0){
                        dp[k][t] = min(dp[k][t],dp[k-(1<<t)][j]+matrix[j][t]);
                    }
                }
            }
        }
    }
    
    int answ=100000000;
    for(int j=1;j<n;j++){
        if(matrix[j][0]){
            if(dp[(1<<n)-1][j]+matrix[j][0]<answ){
                answ=dp[(1<<n)-1][j]+matrix[j][0];
            }
        }
    }

    cout << answ << '\n';
    
    return 0;
}