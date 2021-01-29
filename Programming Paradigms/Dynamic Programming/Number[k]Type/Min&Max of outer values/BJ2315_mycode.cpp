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

int n,m;
int dp[1001][1001][2]; // [leftend][rightend][where], where is 0 if currently at left and 1 if currently at right
int dist[1001];
int weight[1001];
int weightsum[1001];
int bignum=2147483647;

int go(int l,int r,int where){
    if(l==1 && r==n) return 0;
    int& answ= dp[l][r][where];
    if(answ!=-1) return answ;
    answ= bignum;
    int cur= where?r:l;

    int usedsum= weightsum[l-1]+weightsum[n]-weightsum[r];
    if((l-1)>=1){
        answ= min( answ, go(l-1,r,0)+(dist[cur]-dist[l-1])*usedsum );
    }
    if((r+1)<=n){
        answ= min( answ, go(l,r+1,1)+(dist[r+1]-dist[cur])*usedsum );
    }
    return answ;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for(int i=1;i<=n;i++){
        cin >> dist[i] >> weight[i];
    }
    weightsum[1]=weight[1];
    for(int i=2;i<=n;i++){
        weightsum[i]= weightsum[i-1]+weight[i];
    }
    memset(dp,-1,sizeof(dp));
    
    cout << go(m,m,0) << '\n';

    return 0;
}