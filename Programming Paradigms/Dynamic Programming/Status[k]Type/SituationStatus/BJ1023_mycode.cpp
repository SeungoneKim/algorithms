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

long long dp[51][51];

long long calc(int x){
    return (1LL << x);
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;
    
    dp[0][0]=1;
    
    for(int i=1;i<=50;i++){
        dp[i][0] = dp[i-1][1];
        for(int j=1;j<=n;j++){
            dp[i][j] = dp[i-1][j-1];
            if(j+1<=n){
                dp[i][j] += dp[i-1][j+1];
            }
        }
    }

    long long total = calc(n) - dp[n][0];
    if (k >= total) {
        cout << -1 << '\n';
        return 0;
    }

    int open=0;
    for(int i=n;i>=1;i--){
        long long left= calc(i-1);
        if(open>=0) left-=dp[i-1][open+1];
        if(k<left){
            cout << "(";
            open++;
        }
        else{
            cout << ")";
            open--;
            k-= left;
            if(open<0) open-=1000000;
        }
    }
    cout << '\n';
    return 0;
}