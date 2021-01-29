#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

int dp[210][1<<14];
int rownum,colnum;
int mod=9901;

int go(int state,int target){
    // end condition : if there is no block on a imaginary row next to the last row
    if(target==rownum*colnum && state==0){
        return 1;
    }
    if(target>=rownum*colnum){
        return 0;
    }

    int& answ = dp[target][state];
    if(answ!=-1) return answ;
    answ=0;

    // we first check if the target is filled
    if((state & 1)>0){
        answ= go((state>>1),target+1);
        answ %= mod;
    }
    else{
        // we next consider putting 2*1 into the target
        if((state & 2)==0){
            // target shouldn't be the last block on the row
            if((target+1)%colnum!=0){
                answ+= go((state>>2),target+2);
                answ %= mod;
            }
        }

        // lastly we consider putting 1*2 into the target
        answ += go((state>>1)|(1<<(colnum-1)),target+1);
        answ %= mod;
    }
    return answ;
}

int main(){

    cin >> rownum >> colnum;

    memset(dp,-1,sizeof(dp));
    cout << go(0,0) << '\n';

    return 0;
}