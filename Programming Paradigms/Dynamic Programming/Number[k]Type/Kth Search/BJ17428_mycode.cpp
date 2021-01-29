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

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    long long p;
    cin >> n >> p;

    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        dp[0][i]=0;
    }
    for(int k=1;k<=n;k++){
        dp[k][0] = dp[k-1][1];
        for(int t=1;t<n;t++){
            dp[k][t] = dp[k-1][t-1];
            if(t+1<=n){
                dp[k][t] += dp[k-1][t+1];
            }
        }
    }

    if(p>=dp[n][0]){
        cout << -1 << '\n';
        return 0;
    }

    int open=0;
    for(int i=n;i>=1;i--){
        if(open==0){
            cout << '(';
            open++;
        }
        else{
            if(p<dp[i-1][open+1]){
                cout << '(';
                open++;
            }
            else{
                cout << ')';
                p -= dp[i-1][open+1];
                open--;
            }
        }
    }
    cout << '\n';

    return 0;
}