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

int dp[2][100000];

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int n,m;
        cin >> n >> m;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
            a[i]%=m;
        }

        // initialization
        memset(dp,-1,sizeof(dp));
        dp[0][0]=0;

        // dynamic programming
        for(int i=0;i<n;i++){
            int cur=i%2;
            int next=(i+1)%2;
            for(int j=0;j<m;j++){
                dp[next][j]=-1;
            }
            for(int j=0;j<m;j++){
                if(dp[cur][j]==-1) continue;
                // not using i+1th number
                if(dp[cur][j]==-1 || dp[next][j]<dp[cur][j])
                    dp[next][j] = dp[cur][j];
                // using i+1th number
                int k=(j+a[i])%m;
                if(dp[next][k]==-1 || dp[next][k]<dp[cur][j]+1)
                    dp[next][k] = dp[cur][j]+1;
            }
        }

        cout << dp[n%2][0] << '\n';

        memset(dp,0,sizeof(dp));
    }

    return 0;
}