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

int main(){

    int tc;
    cin >> tc;

    while(tc--){
        int n,m;
        cin >> n >> m;

        MaximumFlow mf(n,0,n-1);
        vector<tuple<int,int,int>>edges(m);
        for(int i=0;i<m;i++){
            int a,b,w;
            cin >> a >> b >> w;
            a--; b--;
            get<0>(edges[i])=a;
            get<1>(edges[i])=b;
            get<2>(edges[i])=w;
            mf.add_edge(a,b,w);
        }

        cout << mf.crucial() << '\n';
    }


    return 0;
}