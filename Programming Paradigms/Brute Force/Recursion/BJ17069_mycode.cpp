#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int mat_size;
int mat[33][33];
long long dp[33][33][3];

long long go(int x, int y, int dir){
    if(x==mat_size-1 && y==mat_size-1){
        return 1;
    }
    long long& answ= dp[x][y][dir];
    if(answ!=-1){
        return answ;
    }
    answ=0;
    if(dir==0){
        if(y+1<mat_size && mat[x][y+1]==0){
            answ += go(x,y+1,0);
        }
        if(x+1<mat_size && y+1<mat_size && mat[x][y+1]==0 && mat[x+1][y]==0 && mat[x+1][y+1]==0){
            answ += go(x+1,y+1,1);
        }
    }
    else if(dir==1){
        if(y+1<mat_size && mat[x][y+1]==0){
            answ += go(x,y+1,0);
        }
        if(x+1<mat_size && mat[x+1][y]==0){
            answ += go(x+1,y,2);
        }
        if(x+1<mat_size && y+1<mat_size && mat[x+1][y]==0 && mat[x][y+1]==0 && mat[x+1][y+1]==0){
            answ += go(x+1,y+1,1);
        }
    }
    else if(dir==2){
        if(x+1<mat_size && mat[x+1][y]==0){
            answ += go(x+1,y,2);
        }
        if(x+1<mat_size && y+1<mat_size && mat[x][y+1]==0 && mat[x+1][y]==0 && mat[x+1][y+1]==0){
            answ += go(x+1,y+1,1);
        }
    }
    return answ;
}

int main(){

    cin >> mat_size;
    for(int i=0;i<mat_size;i++){
        for(int j=0;j<mat_size;j++){
            cin >> mat[i][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    cout << go(0,1,0) << '\n';

    return 0;
}