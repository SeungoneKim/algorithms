#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int rownum,colnum;
int matrix[501][501];
int dp[501][501];

int go(int x,int y){
    if(x==rownum && y==colnum){
        return 1;
    }
    if(dp[x][y]!=-1){
        return dp[x][y];
    }
    dp[x][y]=0;
    for(int k=0;k<4;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(1<=nx && nx<=rownum && 1<=ny && ny<=colnum){
            if(matrix[nx][ny]<matrix[x][y]){
                dp[x][y] += go(nx,ny);
            }
        }
    }
    return dp[x][y];
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[1][1]=go(1,1);

    cout << dp[1][1] << '\n';

    return 0;
}