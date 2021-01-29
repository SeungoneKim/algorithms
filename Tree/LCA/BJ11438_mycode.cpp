#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int>adjlist[100001];
bool check[100001];
queue<int>q;

int p[100001][20];
int parent[100001];
int depth[100001];

int lca(int u,int v){
    if(depth[u]<depth[v]){
        swap(u,v);
    }
    int log=1;
    for(log=1;(1<<log)<=depth[u];log++);
    log--;

    for(int i=log;i>=0;i--){
        if(depth[u]-(1<<i)>=depth[v])
            u=p[u][i];
    }

    if(u==v){
        return u;
    }
    else{
        for(int i=log;i>=0;i--){
            if(p[u][i]!=0 && p[u][i]!=p[v][i]){
                u=p[u][i];
                v=p[v][i];
            }
        }
    }
    return parent[u];
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

    for(int k=0;k<=node;k++){
        p[k][0]=parent[k];
    }
    for(int j=1;(1<<j)<=node;j++){
        for(int k=1;k<=node;k++){
            if(p[k][j-1]!=0){
                p[k][j]=p[p[k][j-1]][j-1];
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