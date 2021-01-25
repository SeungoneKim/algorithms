#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

int rownum,colnum;
int matrix[1001][1001];
int dp[1001][1001];

int go(int row,int col){
    if(row==rownum && col==colnum) return matrix[row][col];
    if(row>rownum || col>colnum) return 0;
    int& answ= dp[row][col];
    if(answ>=0) return answ;
    answ=0;

    answ= max(go(row+1,col),go(row,col+1))+matrix[row][col];

    return answ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
        }
    }   

    memset(dp,-1,sizeof(dp));
    
    cout << go(1,1) << '\n';

    return 0;
}