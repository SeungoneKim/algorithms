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
char a[47][47];
int info[47][47]; // 0: X, 1: white with odd number row, 2: black, 3: white with even number row

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

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

int in_node(int r,int c){
    return 2*(r*colnum+c);
}

int out_node(int r,int c){
    return in_node(r,c)+1;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> rownum >> colnum;
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cin >> a[r][c];
        }
    }
    
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            if(a[r][c]!='X'){
                if((r+c)%2==0){
                    info[r][c]=2;
                }
                else{
                    if(r%2==1){
                        info[r][c]=1;
                    }
                    else{
                        info[r][c]=3;
                    }
                }
            }
        }
    }

    MaximumFlow mf(2*rownum*colnum+2,2*rownum*colnum,2*rownum*colnum+1);

    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            if(a[r][c]!='X'){
                mf.add_edge(in_node(r,c),out_node(r,c),1);
                if(info[r][c]==1){
                    mf.add_edge(2*rownum*colnum,in_node(r,c),1);
                }
                else if(info[r][c]==3){
                    mf.add_edge(out_node(r,c),2*rownum*colnum+1,1);
                }
            }
            for(int k=0;k<4;k++){
                int nextr= r+dr[k];
                int nextc= c+dc[k];
                if(0<=nextr && nextr<rownum && 0<=nextc && nextc<colnum){
                    if(info[r][c]==1 && info[nextr][nextc]==2){
                        mf.add_edge(out_node(r,c),in_node(nextr,nextc),1);
                    }
                    if(info[r][c]==2 && info[nextr][nextc]==3){
                        mf.add_edge(out_node(r,c),in_node(nextr,nextc),1);
                    }
                }
            }
        }
    }

    cout << mf.flow() << '\n';

    return 0;
}