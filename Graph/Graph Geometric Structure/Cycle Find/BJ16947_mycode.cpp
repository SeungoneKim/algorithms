#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int>adjlist[3001];
queue<int>q;
int check[3001]; // 0 : not visited, 1 : visited but don't know yet, 2: cycle (if left as 0, it is not cycle)
int dist[3001]; // distance from the cycle

int dfs(int cur, int before){
    /*
    -1 : not found yet
    0 : not cycle
    1~n : cycle
    */
    if(check[cur]==1){
        return cur;
    }
    check[cur]=1;
    for(int next : adjlist[cur]){
        if(next==before) continue;
        int stand = dfs(next,cur);
        if(stand==0) return 0;
        if(stand>=1){
            check[cur]=2;
            if(cur==stand){
                return 0;
            }
            else{
                return stand;
            }
        }
    }
    return -1;
}

int main(){

    // getting inputs
    int num;
    cin >> num;

    for(int k=1;k<=num;k++){
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    // dfs : finding out which vertex is included in the cycle
    int trash = dfs(1,-1);
    
    // bfs : tracking the distance of each vertex
    
    queue<int>q;

    // initializaing
    for(int k=1;k<=num;k++){
        if(check[k]==0){
            check[k]=1;
            dist[k]=-1;
        }
        if(check[k]==1){
            dist[k]=-1;
        }
        if(check[k]==2){
            q.push(k);
            dist[k]=0;
        }
    }

    while(!q.empty()){
        int now=q.front();
        q.pop();
        for(int next : adjlist[now]){
            if(dist[next]==-1){
                q.push(next);
                dist[next]=dist[now]+1;
            }
        }
    }
    
    // printing out the distance of each vertex
    for(int k=1;k<=num;k++){
        cout << dist[k] << ' ';
    }
    cout << '\n';
    
    return 0;
}