#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int a[10001];
vector<int>adjlist[10001];
int dp[10001][2]; // 0: not used, 1: used
vector<int>backtrack;

void go(int idx, int parent){
    for(int i=0;i<(int)adjlist[idx].size();i++){
        if(adjlist[idx][i]==parent) continue;
        go(adjlist[idx][i],idx);
    }

    dp[idx][1]= a[idx];
    dp[idx][0]= 0;

    for(int i=0;i<(int)adjlist[idx].size();i++){
        if(adjlist[idx][i]==parent) continue;
        dp[idx][0] += max(dp[adjlist[idx][i]][0], dp[adjlist[idx][i]][1]);
        dp[idx][1] += dp[adjlist[idx][i]][0];
    }
}

void gogo(int idx, int included, int parent){
    if(included==0){
        for(int i=0;i<(int)adjlist[idx].size();i++){
            if(parent==adjlist[idx][i]) continue;
            if(dp[adjlist[idx][i]][0]<dp[adjlist[idx][i]][1]){
                gogo(adjlist[idx][i],1,idx);
            }
            else{
                gogo(adjlist[idx][i],0,idx);
            }
        }
    }
    else{ // included==1
        backtrack.push_back(idx);
        for(int i=0;i<(int)adjlist[idx].size();i++){
            if(parent==adjlist[idx][i]) continue;
            // if the idx is included, we do not consider the case of child node getting included
            gogo(adjlist[idx][i],0,idx);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    for(int i=1;i<=n-1;i++){
        int b,c;
        cin >> b >> c;
        adjlist[b].push_back(c);
        adjlist[c].push_back(b);
    }

    go(1,0);
    cout << max(dp[1][0],dp[1][1]) << '\n';
    if(dp[1][0]<dp[1][1]){
        gogo(1,1,0);
    }
    else{
        gogo(1,0,1);
    }
    sort(backtrack.begin(),backtrack.end());

    for(int i=0;i<(int)backtrack.size();i++){
        cout << backtrack[i] << ' ';
    }
    cout << '\n';

    return 0;
}