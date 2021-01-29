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
/*
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

int node(string s){
    if(s[0]>='A' && s[0]<='Z'){
        return s[0]-'A';
    }
    else{
        return s[0]-'a'+26;
    }
}
*/
struct MaximumFlow {
    struct Edge {
        int from;
        int to;
        int capacity;
        Edge *rev;
        Edge(int from, int to, int capacity) : from(from), to(to), capacity(capacity) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<Edge *> edges;
    vector<bool> check;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(u,v,cap);
        Edge *rev = new Edge(v,u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
        edges.push_back(ori);
    }
    int bfs() {
        fill(check.begin(), check.end(), false);
        vector<pair<int,int>> from(n, make_pair(-1,-1));
        queue<int> q;
        q.push(source);
        check[source] = true;
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            for (int i=0; i<graph[x].size(); i++) {
                if (graph[x][i]->capacity > 0 && !check[graph[x][i]->to]) {
                    q.push(graph[x][i]->to);
                    check[graph[x][i]->to] = true;
                    from[graph[x][i]->to] = make_pair(x,i);
                }
            }
        }
        if (!check[sink]) {
            return 0;
        }
        int x = sink;
        int c = graph[from[x].first][from[x].second]->capacity;
        while (from[x].first != -1) {
            if (c > graph[from[x].first][from[x].second]->capacity) {
                c = graph[from[x].first][from[x].second]->capacity;
            }
            x = from[x].first;
        }
        x = sink;
        while (from[x].first != -1) {
            Edge *e = graph[from[x].first][from[x].second];
            e->capacity -= c;
            e->rev->capacity += c;
            x = from[x].first;
        }
        return c;
    }
    int flow() {
        int ans = 0;
        while (true) {
            int f = bfs();
            if (f == 0) break;
            ans += f;
        }
        return ans;
    }
    bool dfs(int x, int goal) {
        if (x == goal) {
            return true;
        }
        check[x] = true;
        for (int i=0; i<graph[x].size(); i++) {
            int next = graph[x][i]->to;
            if (!check[next] && graph[x][i]->capacity > 0) {
                if (dfs(next, goal)) {
                    return true;
                }
            }
        }
        return false;
    }
    int crucial() {
        flow();
        int ans = 0;
        for (auto e : edges) {
            fill(check.begin(), check.end(), false);
            if (!dfs(e->from, e->to)) {
                ans += 1;
            }
        }
        return ans;
    }
};
int node(string s) {
    if (s[0] >= 'A' && s[0] <= 'Z') {
        return s[0] - 'A';
    } else {
        return s[0] - 'a' + 26;
    }
}
int n;
MaximumFlow mf(52,0,'Z'-'A');

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    cin >> n;

    for(int i=0;i<n;i++){
        string a,b;
        int w;
        cin >> a >> b >> w;
        int c=node(a);
        int d=node(b);
        mf.add_edge(c,d,w);
        mf.add_edge(d,c,w);
    }
}

int solve(){
    
    int answ= mf.flow();

    return answ;
}

// main function
int main(){

    input();
    cout << solve();
    cout << '\n';

    return 0;
}