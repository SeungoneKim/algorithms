#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adjlist[100001];
bool check[100001];
int dist[100001];
int parent[100001];

int result[100001];
int result_index[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex;
    cin >> vertex;

    for(int k=1;k<=vertex-1;k++){
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    for(int k=1;k<=vertex;k++){
        int x;
        cin >> x;
        result[k]=x;
        result_index[x]=k;
    }

    queue<int>q;

    int start=1;
    check[start]=true;
    dist[start]=0;
    parent[start]=0;
    q.push(1);

    while(!q.empty()){
        int now=q.front();
        q.pop();
        
        for(int next : adjlist[now]){
            if(!check[next]){
                check[next]=true;
                dist[next]=dist[now]+1;
                parent[next]=now;
                q.push(next);
            }
        }
    }
    
    for(int k=1;k<=vertex-1;k++){
        if(dist[result[k]]>dist[result[k+1]] || result_index[parent[result[k]]] > result_index[parent[result[k+1]]]){
            cout << 0 << '\n';
            return 0;
        }
    }
    
    cout << 1 << '\n';
    return 0;
}