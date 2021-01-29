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

int rownum,colnum;

char a[101][101];

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

struct MaximumFlow {
    struct Edge {
        int to;
        int capacity;
        Edge *rev;
        Edge(int to, int capacity) : to(to), capacity(capacity) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    MaximumFlow(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
    };
    void add_edge(int u, int v, int cap) {
        Edge *ori = new Edge(v,cap);
        Edge *rev = new Edge(u,0);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    int bfs() {
        vector<bool> check(n, false);
        vector<pair<int,int>> from(n, make_pair(-1,-1)); // u->v 에서 v 기준으로 from은 {u, 간선이 graph[u]에서 몇번째 간선}을 저장한다.
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
};

int changer_in(int r,int c){
    return 2*(r*colnum+c);
}

int changer_out(int r,int c){
    return changer_in(r,c)+1;
}

int main(){

    int startr,startc,endr,endc;
    cin >> rownum >> colnum;
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cin >> a[r][c];
            if(a[r][c]=='K'){
                startr=r;
                startc=c;
            }
            else if(a[r][c]=='H'){
                endr=r;
                endc=c;
            }
        }
    }
    int inf=1000000;
    // inside mf, we use the node number as (colnum * (curr-1)) + curc
    MaximumFlow mf(2*rownum*colnum,changer_out(startr,startc),changer_in(endr,endc));
    
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            if(a[r][c]=='#') continue;
            mf.add_edge(changer_in(r,c),changer_out(r,c),1);
            for(int k=0;k<4;k++){
                int nextr=r+dr[k];
                int nextc=c+dc[k];
                if(0<=nextr && nextr<rownum && 0<=nextc && nextc<colnum){
                    if(a[nextr][nextc]!='#'){
                        mf.add_edge(changer_out(r,c),changer_in(nextr,nextc),inf);
                    }
                }
            }
        }
    }
    

    
    int answ=mf.flow();
    if(answ>=inf){
        cout << -1 << '\n';
    }
    else{
        cout << answ << '\n';
    }
    

    return 0;
}