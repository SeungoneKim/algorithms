#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>>adjlist[1001];
bool visited[1001];

int main(){

    int vertex, edge;
    cin >> vertex >> edge;

    for(int k=1;k<=edge;k++){
        int a,b,w;
        cin >> a >> b >> w;
        adjlist[a].push_back({b,w});
        adjlist[b].push_back({a,w});
    }

    int answ=0;

    visited[1]=true;
    priority_queue<pair<int,int>>pq;

    for(auto& p : adjlist[1]){
        pq.push({-p.second,p.first});
    }

    while(!pq.empty()){
        auto cur=pq.top();
        pq.pop();
        if(visited[cur.second])continue;
        visited[cur.second]=true;

        answ += -cur.first;
        int x = cur.second;
        for(auto k : adjlist[x]){
            pq.push({-k.second,k.first});
        }
    }

    cout << answ << '\n';

    return 0;
}