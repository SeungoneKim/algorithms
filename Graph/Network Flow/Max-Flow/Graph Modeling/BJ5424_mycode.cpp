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
    void add_edge_from_source(int v, int cap) {
        add_edge(source, v, cap);
    }
    void add_edge_to_sink(int u, int cap) {
        add_edge(u, sink, cap);
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
vector<int> calculate_score(vector<string> &a) {
    int n = a.size();
    vector<int> score(n);
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (a[i][j] == '1') {
                score[i] += 2;
            } else if (a[i][j] == '0') {
                score[j] += 2;
            } else if (a[i][j] == 'd') {
                score[i] += 1;
                score[j] += 1;
            }
        }
    }
    return score;
}
int game(int x, int y, int n) {
    return x*n+y;
}
int player(int x, int n) {
    return n*n+x;
}

bool can_win(vector<string>a,int who){
    int n=(int)a.size();
    for(int i=0;i<n;i++){
        if(a[who][i]=='.'){
            a[who][i]='1';
            a[i][who]='0';
        }
    }
    vector<int>score = calculate_score(a);
    for(int i=0;i<n;i++){
        if(i==who) continue;
        if(score[i]>score[who]) return false;
    }
    int points=0;
    MaximumFlow mf(n*n+n+2,n*n+n,n*n+n+1);
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(a[i][j]=='.'){
                mf.add_edge_from_source(game(i,j,n),2);
                mf.add_edge(game(i,j,n),player(i,n),2);
                mf.add_edge(game(i,j,n),player(j,n),2);
                points+=2;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(who==i) continue;
        mf.add_edge_to_sink(player(i,n),score[who]-score[i]);
    }
    int answ=mf.flow();
    if(answ<points) return false;
    else return true;
}

int main(){

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        
        vector<int>curscore(n);
        vector<pair<int,int>>query;
        vector<string>a(n);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            if(can_win(a,i)){
                cout << i+1 << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}