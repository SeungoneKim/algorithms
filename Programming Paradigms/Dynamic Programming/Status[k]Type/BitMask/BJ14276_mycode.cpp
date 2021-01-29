#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int housenum, roadnum, k;
const long long mod=1000000007LL;
long long dp[30][31][8][1<<9];

int go(int num,int usedroads,int cur,int state){
    if(num==housenum){
        if(usedroads==roadnum){
            if(cur==0 && state==0){
                return 1;
            }
        }
        return 0;
    }
    if(cur==k){
        if((state&(1<<k))==0){
            return go(num+1,usedroads,0,(state<<1));
        }
        else{
            return 0;
        }
    }
    long long& answ= dp[num][usedroads][cur][state];
    if(answ!=-1) return answ;
    answ = go(num,usedroads,cur+1,state);
    if(num-(cur+1)>=0 && usedroads+1<=roadnum){
        answ += go(num,usedroads+1,cur,(state^(1<<0)^(1<<(cur+1))));
    }
    answ %= mod;
    return answ;
}

int main(){

    
    cin >> housenum >> roadnum >> k;

    memset(dp,-1,sizeof(dp));

    cout << go(0,0,0,0) << '\n';

    return 0;
}