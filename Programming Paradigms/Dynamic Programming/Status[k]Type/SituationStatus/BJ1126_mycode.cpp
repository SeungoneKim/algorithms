#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int n;
int numbers[51];
int dp[51][250001];//[until which block is considered][difference]
int sum[51];
int infinity=100000000;

int go(int idx,int diff){
    if(diff>250000){
        return -infinity;
    }
    if(idx==n){
        if(diff==0){
            return 0;
        }
        else{
            return -infinity;
        }
    }
    int& answ=dp[idx][diff];
    if(answ!=-1) return answ;

    answ= go(idx+1,diff);
    
    answ= max(answ,go(idx+1,diff+numbers[idx]));
    
    if(diff>=numbers[idx]){
        answ = max(answ,numbers[idx]+go(idx+1,diff-numbers[idx]));
    }
    else{
        answ = max(answ,diff+go(idx+1,numbers[idx]-diff));
    }

    return answ;
}

int main(){

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> numbers[i];
    }

    memset(dp,-1,sizeof(dp));
    int answ = go(0,0);

    if (answ == 0) {
        cout << -1 << '\n';
    } 
    else {
        cout << answ << '\n';
    }
    

    return 0;
}