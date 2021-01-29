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
char a[50][50];
int rowinfo[50][50];
int colinfo[50][50];

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

// main function
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    

    cin >> rownum >> colnum;
    
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cin >> a[r][c];
        }
    }


    // .*. **. .** ***
    int rowgroup=1;
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            if(a[r][c]=='*'){
                rowinfo[r][c]=rowgroup;
                if(c==colnum-1){
                    rowgroup++;
                }
                else{
                    if(a[r][c+1]=='.'){
                        rowgroup++;
                    }
                }
            }
        }
    }
    int colgroup=1;
    for(int c=0;c<colnum;c++){
        for(int r=0;r<rownum;r++){
            if(a[r][c]=='*'){
                colinfo[r][c]=colgroup;
                if(r==rownum-1){
                    colgroup++;
                }
                else{
                    if(a[r+1][c]=='.'){
                        colgroup++;
                    }
                }
            }
        }
    }

    rowgroup--;
    colgroup--;
    
    MaximumFlow mf(max(rowgroup,colgroup));
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            if(rowinfo[r][c]>0 && colinfo[r][c]>0){
                mf.add_edge(rowinfo[r][c]-1,colinfo[r][c]-1);
            }
        }
    }

    cout << mf.flow() << '\n';

    return 0;
}