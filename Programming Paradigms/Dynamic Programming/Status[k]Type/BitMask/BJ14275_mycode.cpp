#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int rownum,colnum;
int total;
long long dp[800][19683];
const long long mod=1000000007LL;
long long pow3[9];

int go(int rmo,int state){
    if(rmo==total){
        while(state>0){
            if(state%3==1) return 0;
            state /=3;
        }
        return 1;
    }
    long long& answ= dp[rmo][state];
    if(answ!=-1) return answ;
    answ=0;
    int up = (state/pow3[colnum-1]) % 3;
    int left= (state/pow3[0]) % 3;
    int cleft=2;
    if(left==0){
        cleft=1;
    }
    else if(left==1){
        cleft=0;
    }
    int cur=0;
    // considering left situation for now
    if(left!=2){
        cur=1;
    }
    // left most situation
    if(rmo%colnum==0){
        cleft=left;
        cur=0;
    }
    int nstate= (state-up*pow3[colnum-1]-left*pow3[0])*3;

    if(up==2){
        answ+= go(rmo+1,nstate+left*pow3[1]+2);
        answ+= go(rmo+1,nstate+cleft*pow3[1]+cur);
    }
    else{
        cur = 1-cur;
        if(up==0){
            answ += go(rmo+1,nstate+left*pow3[1]+2);
        }
        else{
            answ += go(rmo+1,nstate+cleft*pow3[1]+cur);
        }
    }
    answ %= mod;
    return answ;
}

int main(){

    cin >> rownum >> colnum;
    pow3[0] = 1;
    for (int i=1; i<=colnum; i++) {
        pow3[i] = pow3[i-1] * 3;
        pow3[i] %= mod;
    }
    total=rownum*colnum;
    
    memset(dp,-1,sizeof(dp));

    int state=0;
    for(int i=0;i<colnum;i++){
        state = state*3+2;
    }
    cout << go(0,state) << '\n';

    return 0;
}