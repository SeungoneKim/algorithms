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
#include <bitset>

using namespace std;


const int MAX=1132500;
int a[151];
int tmps[151];
int s[151][151];
bitset<MAX+1>dp[151];

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> a[i];
        tmps[i] = tmps[i-1]+a[i];
    }
    int k;
    cin >> k;

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            s[i][j] = s[i][j-1]+tmps[j]-tmps[i-1];
        }
    }

    if(k>s[1][n]){
        cout << k << '\n';
        return 0;
    }

    dp[0].set(0);
    dp[1].set(0); dp[1].set(a[1]);
    for(int i=2;i<=n;i++){
        for(int j=1;j<=i+1;j++){
            if(j<=2){
                dp[i].set(s[j][i]);
            }
            else{
                dp[i] |= (dp[j-2] << s[j][i]);
            }
        }
    }

    while(true){
        if(dp[n].test(k)==0){
            cout << k << '\n';
            break;
        }
        k++;
    }

    return 0;
}