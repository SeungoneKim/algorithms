#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int t,a,s,b;
long long dp[201][4001]; // [consideration 1~n][howmany numbers used until right before]
int used[4001];
long long mod=1000000;

long long go(int len,int howmany, const int& thismuch){
    
    if(howmany==thismuch){
        return 1;
    }
    if(len==t+1 && howmany!=thismuch){
        return 0;
    }
    
    long long& answ= dp[len][howmany];
    if(answ>0) return answ;
    answ=0;

    for(int k=0;k<=used[len];k++){
        if(howmany+k<=thismuch){
            answ += go(len+1,howmany+k,thismuch)%mod;
            answ %= mod;
        }
    }

    return answ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t >> a >> s >> b;

    for(int k=1;k<=a;k++){
        int tmp;
        cin >> tmp;
        used[tmp]++;
    }

    long long answ=0;
    for(int k=s;k<=b;k++){
        answ += go(1,0,k)%mod;
        answ %= mod;
    }

    cout << answ << '\n';

    return 0;
}