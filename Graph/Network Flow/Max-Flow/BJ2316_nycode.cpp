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
#include <bitset>

using namespace std;

int infinity=100000000;

struct MaximumFlow{
    struct Edge{
        int to;
        int capacity;
        Edge* rev;
        Edge(int to,int capacity) : to(to), capacity(capacity)
        {}
    };

    int n;
    int source,sink;
    vector<vector<Edge*>>graph;
    vector<bool>check;
    MaximumFlow(int n,int source,int sink): n(n),source(source), sink(sink)
    {
        graph.resize(n);
        check.resize(n);
    };

    void add_edge(int u,int v,int cap){
        Edge* ori = new Edge(v,cap);
        Edge* rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    int dfs(int x,int c){
        if(check[x]) return 0;
        check[x]= true;
        if(x==sink) return c;
        
        for(int i=0;i<graph[x].size();i++){
            if(graph[x][i]->capacity>0){
                int nc= graph[x][i]->capacity;
                if(c!=0 && c<nc){
                    nc=c;
                }
                int f= dfs(graph[x][i]->to, nc);
                if(f){
                    graph[x][i]->capacity -= f;
                    graph[x][i]->rev->capacity += f;
                    return f;
                }
            }
        }
        return 0;
    }
    int flow(){
        int answ=0;
        while(true){
            fill(check.begin(),check.end(),false);
            int f=dfs(source,0);
            if(f==0) break;
            answ+=f;
        }
        return answ;
    }
};
int node_in(int t){
    return 2*(t-1);
}
int node_out(int t){
    return 2*t-1;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int townnum,roadnum;
    cin >> townnum >> roadnum;

    MaximumFlow mf(2*townnum,0,3);
    for(int i=0;i<roadnum;i++){
        int a,b;
        cin >> a >> b;
        mf.add_edge(node_out(a),node_in(b),infinity);
        mf.add_edge(node_out(b),node_in(a),infinity);
    }
    mf.add_edge(node_in(1),node_out(1),infinity);
    mf.add_edge(node_in(2),node_out(2),infinity);
    for(int i=3;i<=townnum;i++){
        mf.add_edge(node_in(i),node_out(i),1);
    }

    cout << mf.flow() << '\n';

    return 0;
}