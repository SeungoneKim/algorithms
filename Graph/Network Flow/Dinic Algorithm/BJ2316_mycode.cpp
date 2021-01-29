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

int n,p;
int INF=100000000;

struct Dinic {
    struct Edge {
        int to, cap;
        Edge *rev;
        Edge(int to, int cap) : to(to), cap(cap) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<int> start;
    vector<int> level;
    Dinic(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        start.resize(n);
        level.resize(n);
    }
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v, cap);
        Edge *rev = new Edge(u, 0);
        ori->rev = rev;
        rev->rev = rev;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap) {
        add_edge(source, v, cap);
    }
    void add_edge_to_sink(int u, int cap) {
        add_edge(u, sink, cap);
    }
    void bfs() {
        fill(level.begin(), level.end(), -1);
        queue<int> q;
        level[source] = 0;
        q.push(source);
        while (!q.empty()) {
            int x = q.front(); q.pop();
            for (auto &e : graph[x]) {
                int y = e->to;
                int cap = e->cap;
                if (cap > 0 && level[y] == -1) {
                    level[y] = level[x] + 1;
                    q.push(y);
                }
            }
        }
    }
    int dfs(int x, int f) {
        if (x == sink) return f;
        for (int &i=start[x]; i<graph[x].size(); i++) {
            auto &e = graph[x][i];
            int y = e->to;
            int cap = e->cap;
            if (cap > 0 && level[y] == level[x]+1) {
                int nf = cap;
                if (f != -1 && nf > f) nf = f;
                int t = dfs(y, nf);
                if (t > 0) {
                    e->cap -= t;
                    e->rev->cap += t;
                    return t;
                }
            }
        }
        return 0;
    }
    int flow() {
        int ans = 0;
        while (true) {
            bfs();
            if (level[sink] == -1) break;
            fill(start.begin(), start.end(), 0);
            while (true) {
                int f = dfs(source, -1);
                if (f > 0) {
                    ans += f;
                } else {
                    break;
                }
            }
        }
        return ans;
    }
};

int innode(int a){
    return a-1;
}
int outnode(int a){
    return n-1+a;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> p;

    Dinic din(2*n,innode(1),outnode(2));
    din.add_edge(innode(1),outnode(1),INF);
    din.add_edge(innode(2),outnode(2),INF);
    for(int i=3;i<=n;i++){
        din.add_edge(innode(i),outnode(i),1);
    }

    for(int i=1;i<=p;i++){
        int a,b;
        cin >> a >> b;
        din.add_edge(outnode(a),innode(b),INF);
        din.add_edge(outnode(b),innode(a),INF);
    }

    cout << din.flow() << '\n';

    return 0;
}