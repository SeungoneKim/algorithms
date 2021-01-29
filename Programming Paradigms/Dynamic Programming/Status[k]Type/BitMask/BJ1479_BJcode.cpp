#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

pair<int,int> dp[2501][51][1<<4]; // index, covered, mask
string a[4];
string str;

pair<int,int>go(int idx,int covered,int mask){
    if(mask==0){
        return {0,0};
    }
    auto& answ=dp[idx][covered][mask];
    if(answ.first!=-1) return answ;

    answ= {1000000,-1000000};
    if(idx==str.size()){
        return answ;
    }
    answ=go(idx+1,max(0,covered-1),mask);
    for(int i=0;i<4;i++){
        if(mask & (1<<i)){
            if(str.substr(idx,a[i].size())==a[i]){
                int nextc=0;
                if(a[i].size()>covered){
                    nextc=(int)a[i].size()-covered;
                }
                auto temp=go(idx,max(covered,(int)a[i].size()),mask-(1<<i));
                answ = {min(temp.first+nextc,answ.first),max(temp.second+nextc,answ.second)};
            }
        }
    }
    return answ;
}

int main(){

    cin >> str;

    for(int i=0;i<4;i++){
        cin >> a[i];
    }
    sort(a,a+4);
    memset(dp,-1,sizeof(dp));
    auto answ= go(0,0,15);
    cout << answ.first << ' ' << answ.second << '\n';

    return 0;
}