#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <vector>

using namespace std;

int n,red,blue,green;

long long dp[11][101][101][101];
long long c[11][11];

long long go(int idx,int r,int b,int g){
    if(idx==0){
        return 1;
    }
    if(dp[idx][r][b][g]!=-1){
        return dp[idx][r][b][g];
    }
    long long& answ=dp[idx][r][b][g];
    answ=0;
    if(idx%3==0){
        int eachone=idx/3;
        if(r-eachone>=0 && b-eachone>=0 && g-eachone>=0){
            answ += go(idx-1,r-eachone,b-eachone,g-eachone)*c[idx][eachone]*c[idx-eachone][eachone];
        }
    }
    if(idx%2==0){
        int eachone=idx/2;
        if(r-eachone>=0 && b-eachone>=0){
            answ += go(idx-1,r-eachone,b-eachone,g)*c[idx][eachone];
        }
        if(r-eachone>=0 && g-eachone>=0){
            answ += go(idx-1,r-eachone,b,g-eachone)*c[idx][eachone];
        }
        if(g-eachone>=0 && b-eachone>=0){
            answ += go(idx-1,r,b-eachone,g-eachone)*c[idx][eachone];
        }
    }
    if(r>=idx){
        answ += go(idx-1,r-idx,b,g);
    }
    if(b>=idx){
        answ += go(idx-1,r,b-idx,g);
    }
    if(g>=idx){
        answ += go(idx-1,r,b,g-idx);
    }
    return answ;
}

int main(){

    cin >> n >> red >> blue >> green;

    c[0][0]=1;
    for(int i=1;i<=10;i++){
        c[i][0]=c[i][i]=1;
        for(int j=1;j<i;j++){
            c[i][j] = c[i-1][j-1] + c[i-1][j];
        }
    }

    memset(dp,-1,sizeof(dp));
    
    cout << go(n,red,blue,green) << '\n';

    return 0;
}