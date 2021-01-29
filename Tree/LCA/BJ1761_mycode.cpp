#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>>adjlist[50001];
bool check[50001];
queue<int>q;

int dist_from_1[50001];
int parent[50001];
int depth[50001];

int lca(int u,int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    while(depth[u]!=depth[v]){
        u=parent[u];
    }
    while(u!=v){
        u=parent[u];
        v=parent[v];
    }
    return u;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int node;
    cin >> node;

    for(int k=1;k<=(node-1);k++){
        int a,b,w;
        cin >> a >> b >> w;
        adjlist[a].push_back({b,w});
        adjlist[b].push_back({a,w});
    }

    check[1]=true;
    q.push(1);
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(auto&a : adjlist[cur]){
            int next=a.first;
            int nextw=a.second;
            if(!check[next]){
                check[next]=true;
                depth[next]=depth[cur]+1;
                parent[next]=cur;
                dist_from_1[next]=dist_from_1[cur]+nextw;
                q.push(next);
            }
        }
    }

    int query;
    cin >> query;
    while(query--){
        int a,b;
        cin >> a >> b;
        int x= lca(a,b);
        cout << dist_from_1[a]+dist_from_1[b]-2*dist_from_1[x] << '\n';
    }

    return 0;
}