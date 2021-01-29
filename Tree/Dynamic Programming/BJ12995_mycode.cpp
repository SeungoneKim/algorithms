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

const long long mod=1000000007LL;
vector<int>adjlist[51];
vector<int>tree[51]; // change to undirected graph, so we don't have to consider calling parent at go()
long long dp[51][51][51]; // [idx][which child node have you already considered][how many people left to assign]

void dfs(int idx,int parent){
    for(int y:adjlist[idx]){
        if(y==parent) continue;
        tree[idx].push_back(y);
        dfs(y,idx);
    }
}

int go(int idx,int k,int e){
    long long& answ= dp[idx][k][e];
    if(answ!=-1) return answ;
    // already all assigned
    if(k==0){
        return 1;
    }
    // at bottom of tree
    if(e==tree[idx].size()){
        if(k==1) return 1;
        else return 0;
    }
    answ=0;
    for(int i=0;i<k;i++){
        long long tmp1= go(tree[idx][e],i,0);
        long long tmp2= go(idx,k-i,e+1);
        answ += tmp1*tmp2;
        answ %= mod;
    }
    return answ;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    for(int i=1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    dfs(0,-1);

    memset(dp,-1,sizeof(dp));
    long long answer=0;
    for(int i=1;i<=n;i++){
        answer += go(i,k,0);
        answer %=mod;
    }
    answer %=mod;

    cout << answer << '\n';

    return 0;
}