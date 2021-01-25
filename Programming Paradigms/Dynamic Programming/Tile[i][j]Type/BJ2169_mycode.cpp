#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int matrix[1002][1002];
int dp[1002][1002][3]; // 0 :up, 1:left, 2:right
int infinity=1000000000;

int main(){

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
        }
    }   
    fill(&dp[0][0][0],&dp[1001][1001][2]+1,-infinity);
    
    dp[1][1][1]=matrix[1][1];
    for(int j=2;j<=colnum;j++){
        dp[1][j][1] = dp[1][j-1][1]+matrix[1][j];
    }

    for(int r=2;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            dp[r][c][0] = max(max(dp[r-1][c][0],dp[r-1][c][1]),dp[r-1][c][2])+matrix[r][c];
            dp[r][c][1] = max(dp[r][c-1][0],dp[r][c-1][1])+matrix[r][c];
        }
        for(int c=colnum;c>=1;c--){
            dp[r][c][2] = max(dp[r][c+1][0],dp[r][c+1][2])+matrix[r][c];
        }
    }

    int answ= max(dp[rownum][colnum][0],dp[rownum][colnum][1]);
    cout << answ << '\n';

    return 0;
}