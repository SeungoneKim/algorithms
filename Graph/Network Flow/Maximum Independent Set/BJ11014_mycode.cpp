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

// Global variables
int rownum, colnum;

// Global arrays
char a[81][81];

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

struct MaximumFlow{
    int n;
    int source,sink;
    vector<vector<int>>graph;
    vector<bool>check;
    vector<int>pred;
    MaximumFlow(int n): n(n)
    {
        graph.resize(n);
        check.resize(n);
        pred.resize(n,-1); 
    };

    void add_edge(int u,int v){
        graph[u].push_back(v);
    }
    bool dfs(int x){
        if(x==-1) return true;
        
        for(int next : graph[x]){
            if(check[next]) continue;
            check[next]=true;
            if(dfs(pred[next])){ // since pred[next]==-1 at initialization, it will return true if going to sink
                pred[next]=x;
                return true;
            }
        }
        return false;
    }
    int flow(){
        int answ=0;
        for(int i=0;i<n;i++){
            fill(check.begin(),check.end(),false);
            if(dfs(i)){
                answ+=1;
            }
        }
        return answ;
    }
};
int node(int x, int y, int m) {
    return x*m+y;
}

// main function
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);  

    int tc;
    cin >> tc;  
    
    while(tc--){
        cin >> rownum >> colnum;

        MaximumFlow mf(rownum*colnum);
        for(int r=0;r<rownum;r++){
            for(int c=0;c<colnum;c++){
                cin >> a[r][c];
            }
        }

        for(int r=0;r<rownum;r++){
            for(int c=0;c<colnum;c++){
                if(a[r][c]=='x') continue;
                if((r>0) && (c>0)){
                    if(a[r-1][c-1]=='.'){
                        if(c%2==0){
                            mf.add_edge(node(r,c,colnum),node(r-1,c-1,colnum));
                        }
                        else{
                            mf.add_edge(node(r-1,c-1,colnum),node(r,c,colnum));
                        }
                    }
                }
                if((r>0) && (c+1<colnum)){
                    if(a[r-1][c+1]=='.'){
                        if(c%2==0){
                            mf.add_edge(node(r,c,colnum),node(r-1,c+1,colnum));
                        }
                        else{
                            mf.add_edge(node(r-1,c+1,colnum),node(r,c,colnum));
                        }
                    }
                }
                if(c>0){
                    if(a[r][c-1]=='.'){
                        if(c%2==0){
                            mf.add_edge(node(r,c,colnum),node(r,c-1,colnum));
                        }
                        else{
                            mf.add_edge(node(r,c-1,colnum),node(r,c,colnum));
                        }
                    }
                }
            }
        }
        int answ=0;
        for(int r=0;r<rownum;r++){
            for(int c=0;c<colnum;c++){
                if(a[r][c]=='.'){
                    answ++;
                }
            }
        }

        cout << answ-mf.flow() << '\n';


    }

    return 0;
}