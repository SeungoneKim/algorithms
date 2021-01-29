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

struct MCMF {
    struct Edge {
        int to;
        int capacity;
        int cost;
        Edge *rev;
        Edge(int to, int capacity, int cost) : to(to), capacity(capacity), cost(cost) {
        }
    };
    int n;
    int source, sink;
    vector<vector<Edge *>> graph;
    vector<bool> check;
    vector<int> distance;
    vector<pair<int,int>> from;
    int inf = 10000000;
    MCMF(int n, int source, int sink) : n(n), source(source), sink(sink) {
        graph.resize(n);
        check.resize(n);
        from.resize(n, make_pair(-1,-1));
        distance.resize(n);
    };
    void add_edge(int u, int v, int cap, int cost) {
        Edge *ori = new Edge(v,cap,cost);
        Edge *rev = new Edge(u,0,-cost);
        ori->rev = rev;
        rev->rev = ori;
        graph[u].push_back(ori);
        graph[v].push_back(rev);
    }
    void add_edge_from_source(int v, int cap, int cost) {
        add_edge(source, v, cap, cost);
    }
    void add_edge_to_sink(int u, int cap, int cost) {
        add_edge(u, sink, cap, cost);
    }
    bool spfa(int &total_flow, int &total_cost) {
        fill(check.begin(), check.end(), false);
        fill(distance.begin(), distance.end(), inf);
        fill(from.begin(), from.end(), make_pair(-1,-1));
        distance[source] = 0;
        queue<int> q;
        q.push(source);
        while (!q.empty()) {
            int x = q.front();
            q.pop();
            check[x] = false;
            for (int i=0; i<graph[x].size(); i++) {
                auto e = graph[x][i];
                int y = e->to;
                if (e->capacity > 0 && distance[x] + e->cost < distance[y]) {
                    distance[y] = distance[x] + e->cost;
                    from[y] = make_pair(x,i);
                    if (!check[y]) {
                        check[y] = true;
                        q.push(y);
                    }
                }
            }
        }
        if (distance[sink] == inf) {
            return false;
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
        total_flow += c;
        total_cost += c*distance[sink];
        return true;
    }
    pair<int,int> flow() {
        int total_flow = 0;
        int total_cost = 0;
        while (spfa(total_flow, total_cost));
        return make_pair(total_flow, total_cost);
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int carnum;
    cin >> carnum;

    vector<int>timein(carnum);
    vector<int>timeout(carnum);
    for(int i=0;i<carnum;i++){
        cin >> timein[i];
    }
    for(int i=0;i<carnum;i++){
        cin >> timeout[i];
    }

    int standard;
    cin >> standard;
    int maxcost;
    cin >> maxcost;

    MCMF mf1(2*carnum+2,2*carnum,2*carnum+1);
    MCMF mf2(2*carnum+2,2*carnum,2*carnum+1);

    for(int i=0;i<carnum;i++){
        for(int j=0;j<carnum;j++){
            int diff= timeout[j]-timein[i];
            
            if(diff<=0) continue;

            if(diff<standard){
                int penalty= (standard-diff)*(standard-diff);
                if(penalty>maxcost) penalty=maxcost;
                mf1.add_edge(i,carnum+j,1,penalty);
                mf2.add_edge(i,carnum+j,1,-penalty);
            }
            else{
                mf1.add_edge(i,carnum+j,1,0);
                mf2.add_edge(i,carnum+j,1,0);
            }
        }
    }

    for(int i=0;i<carnum;i++){
        mf1.add_edge_from_source(i,1,0);
        mf1.add_edge_to_sink(i+carnum,1,0);
        mf2.add_edge_from_source(i,1,0);
        mf2.add_edge_to_sink(i+carnum,1,0);
    }

    auto ans=mf1.flow();
    auto ans2=mf2.flow();

    if(ans.first!=carnum){
        cout << -1 << '\n';
    }
    else{
        cout << ans.second << ' ' << -ans2.second << '\n';
    }

    return 0;
}