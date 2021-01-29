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

long long mod=1000000009LL;

long long dp[1000001][7];

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    dp[1][1]=1;
    dp[1][0]=k-1;

    for(int i=2;i<=n;i++){
        //from state0
        dp[i][1] += dp[i-1][0]; // A
        dp[i][0] += dp[i-1][0]*(k-1);

        //from state1
        dp[i][2] += dp[i-1][1]; // B
        dp[i][0] += dp[i-1][1]*(k-2);
        dp[i][1] += dp[i-1][1]; // A

        //from state2
        dp[i][4] += dp[i-1][2]; // A
        dp[i][3] += dp[i-1][2]; // C
        dp[i][0] += dp[i-1][2]*(k-2);

        //from state3
        dp[i][5] += dp[i-1][3]; // B
        dp[i][1] += dp[i-1][3]; // A
        dp[i][0] += dp[i-1][3]*(k-2);

        //from state4
        dp[i][1] += dp[i-1][4]; // A
        dp[i][6] += dp[i-1][4]; // B
        dp[i][0] += dp[i-1][4]*(k-2);

        //from state5
        dp[i][1] += dp[i-1][5]; // A
        
        dp[i][0] += dp[i-1][5]*(k-2);

        //from state6
        dp[i][4] += dp[i-1][6]; // A

        dp[i][0] += dp[i-1][6]*(k-2);

        for(int j=0;j<=6;j++){
            dp[i][j] %= mod;
        }
    }

    long long answ=0;
    for(int j=0;j<=6;j++){
        answ+= dp[n][j];
        answ %= mod;
    }

    cout << answ << '\n';

    return 0;
}