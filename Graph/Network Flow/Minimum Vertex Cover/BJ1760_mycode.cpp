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

int a[100][100];
int rowinfo[100][100];
int colinfo[100][100];

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

int main(){

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cin >> a[r][c];
        }
    }

    int rowgroup=1;
    int colgroup=1;

    for(int r=0;r<rownum;r++){ 
        for(int c=0;c<colnum;c++){
            if(a[r][c]!=2){
                rowinfo[r][c]=rowgroup;
                if(c==colnum-1){
                    rowgroup++;
                }
                else if(a[r][c+1]==2){
                    rowgroup++;
                }
            }
        }
    }
    
    for(int c=0;c<colnum;c++){
        for(int r=0;r<rownum;r++){
            if(a[r][c]!=2){
                colinfo[r][c]=colgroup;
                if(r==rownum-1){
                    colgroup++;
                }
                else if(a[r+1][c]==2){
                    colgroup++;
                }
            }
        }
    }
    /*
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cout << rowinfo[r][c] << ' ';
        }
        cout << '\n';
    }
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cout << colinfo[r][c] << ' ';
        }
        cout << '\n';
    }
    */
    rowgroup--;
    colgroup--;

    MaximumFlow mf(max(rowgroup,colgroup));

    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            if(rowinfo[r][c]>0 && colinfo[r][c]>0 && a[r][c]==0){
                mf.add_edge(rowinfo[r][c]-1,colinfo[r][c]-1);
            }
        }
    }

    cout << mf.flow() << '\n';

    return 0;
}