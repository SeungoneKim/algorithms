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
long long dp[32][32];

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,l;
    long long i;
    cin >> n >> l >> i;

    for(int j=0;j<=l;j++){
        dp[0][j]=1;
    }
    for(int t=1;t<=31;t++){
        dp[t][0] = dp[t-1][0];
        for(int j=1;j<=31;j++){
            dp[t][j]=dp[t-1][j-1]+dp[t-1][j]; 
        }
    }

    while(n>0){
        if(i<=dp[n-1][l]){
            cout << "0";
            n--;
        }
        else{
            cout << "1";
            i-=dp[n-1][l];
            l--;
            n--;
        }
    }
    cout << '\n';

    return 0;
}