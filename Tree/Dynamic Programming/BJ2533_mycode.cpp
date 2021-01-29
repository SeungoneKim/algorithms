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

vector<int>adjlist[1000001];
int dp[1000001][2]; // 0: not an early adapter, 1: an early adapter

void go(int idx,int parent){
    for(int i=0;i<(int)adjlist[idx].size();i++){
        if(parent==adjlist[idx][i]) continue;
        go(adjlist[idx][i],idx);
    }

    dp[idx][0] =0;
    dp[idx][1] =1;
    for(int i=0;i<(int)adjlist[idx].size();i++){
        if(parent==adjlist[idx][i]) continue;
        dp[idx][0] += dp[adjlist[idx][i]][1];
        dp[idx][1] += min(dp[adjlist[idx][i]][0],dp[adjlist[idx][i]][1]);
    }
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    go(1,0);
    cout << min(dp[1][0],dp[1][1]) << '\n';

    return 0;
}