#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int>adjlist[50001];
bool check[50001];
queue<int>q;

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
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    check[1]=true;
    q.push(1);
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int next : adjlist[cur]){
            if(!check[next]){
                check[next]=true;
                depth[next]=depth[cur]+1;
                parent[next]=cur;
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
        cout << x << '\n';
    }

    return 0;
}