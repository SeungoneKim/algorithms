#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int matrix[101][101];
long long dp[101][101];

int main(){

    int size;
    cin >> size;

    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            cin >> matrix[r][c];
        }
    }

    dp[1][1]=1;
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            if(r==size && c==size) continue;
            if(r+matrix[r][c]<=size){
                dp[r+matrix[r][c]][c] += dp[r][c];
            }
            if(c+matrix[r][c]<=size){
                dp[r][c+matrix[r][c]] += dp[r][c];
            }
        }
    }

    cout << dp[size][size] << '\n';

    return 0;
}