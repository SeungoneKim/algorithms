#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int dist[301][301];
int dp[301][301]; //[which_city][how_many_moves]

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,roads;
    cin >> n >> m >> roads;

    memset(dist,-1,sizeof(dist));
    while(roads--){
        int a,b,c;
        cin >> a >> b >> c;
        if(a<=b){
            dist[a][b]=max(dist[a][b],c);
        }
    }
    memset(dp,-1,sizeof(dp));
    dp[1][1]=0;
    for (int j=1; j<=m-1; j++) {
        for (int i=1; i<=n; i++) {
            if (dp[i][j] == -1) {
                continue;
            }
            for (int k=i+1; k<=n; k++) {
                if (dist[i][k] > 0) {
                    dp[k][j+1] = max(dp[k][j+1], dp[i][j] + dist[i][k]);
                }
            }
        }
    }

    int answ=0;
    for(int i=0;i<=m;i++){
        answ = max(answ,dp[n][i]);
    }

    cout << answ << '\n';

    return 0;
}