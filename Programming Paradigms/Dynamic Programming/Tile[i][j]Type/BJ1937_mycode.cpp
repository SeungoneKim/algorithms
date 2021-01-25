#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int matrix_size;

int matrix[501][501];
int dp[501][501];

int go(int x,int y){
    if(dp[x][y]!=0){
        return dp[x][y];
    }
    dp[x][y]=1;
    for(int k=0;k<4;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(1<=nx && nx<=matrix_size && 1<=ny && ny<=matrix_size){
            if(matrix[x][y]<matrix[nx][ny]){
                dp[x][y]=max(dp[x][y],go(nx,ny)+1);
            }
        }
    }
    return dp[x][y];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> matrix_size;
    for(int r=1;r<=matrix_size;r++){
        for(int c=1;c<=matrix_size;c++){
            cin >> matrix[r][c];
        }
    }
    int answ=0;
    for(int r=1;r<=matrix_size;r++){
        for(int c=1;c<=matrix_size;c++){
            dp[r][c]=go(r,c);
            if(dp[r][c]>answ){
                answ=dp[r][c];
            }
        }
    }

    cout << answ << '\n';

    return 0;
}