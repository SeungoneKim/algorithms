#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int dp[101][101];

bool go(int x,int y){
    if(dp[x][y]!=-1){
        return dp[x][y];
    }

    int& answ=dp[x][y];
    answ=0;

    for(int i=1;i<=y;i++){
        if(go(i,y-i)==0){
            dp[x][y]=1;
        }
    }
    for(int i=1;i<=x;i++){
        if(go(i,x-i)==0){
            dp[x][y]=1;
        }
    }
    return answ;
}

int main(){

    int n,m;
    cin >> n >> m;
    
    memset(dp,-1,sizeof(dp));
    dp[1][1]=0;
    int answ=go(n,m);

    if(answ==1){
        cout << "A\n";
    }
    else{
        cout << "B\n";
    }

    return 0;
}