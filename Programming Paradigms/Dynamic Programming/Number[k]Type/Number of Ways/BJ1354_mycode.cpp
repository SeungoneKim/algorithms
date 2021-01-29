#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <climits>

using namespace std;

long long dp[5000001];
long long p,q,x,y;

long long go(long long i){
    if(i<=0){
        return 1LL;
    }
    
    if(i<=5000000 && dp[i]!=0){
        return dp[i];
    }
    long long answ= go((i/p)-x) + go((i/q)-y);
    if(i<=5000000){
        dp[i] = answ;
    }
    return answ;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    cin >> n >> p >> q >> x >> y;

    cout << go(n) << '\n';

    return 0;
}