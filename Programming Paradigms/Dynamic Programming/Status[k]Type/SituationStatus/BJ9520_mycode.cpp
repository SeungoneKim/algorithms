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

int n;
int cost[1501][1501];
int dp[1501][1501];
bool visited[1501][1501];

int go(int l,int r){
    if(dp[l][r]) return dp[l][r];
    int next=max(l,r)+1;
    if(next==n+1) return 0;

    dp[l][r]= min(cost[next][l]+go(next,r),cost[next][r]+go(l,next));
    return dp[l][r];
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int f=1;f<=n;f++){
        for(int t=1;t<=n;t++){
            cin >> cost[f][t];
        }
    }

    cout << go(1,1) << '\n';

    return 0;
}