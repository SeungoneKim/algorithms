#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int matrix[1001][1001];
int dp[1001][1001];

int main(){

    int rownum, colnum;
    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        string s;
        cin >> s;    
        for(int c=1;c<=colnum;c++){
            matrix[r][c]=s[c-1]-'0';
            if(matrix[r][c]==1){
                dp[r][c]=1;
            }
        }
    }

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(matrix[r][c]==1){
                dp[r][c]= min(min(dp[r-1][c],dp[r][c-1]),dp[r-1][c-1])+1;
            }
        }
    }

    int answ=0;
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(dp[r][c]>answ){
                answ = dp[r][c];
            }
        }
    }
    
    cout << answ * answ << '\n';

    return 0;
}