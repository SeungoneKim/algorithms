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
int leftdown_diag[100][100];
int rightdown_diag[100][100];

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

    int rownum, colnum;
    cin >> rownum;
    colnum=rownum;
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            rightdown_diag[r][c]=(rownum-1-r)+c;
            leftdown_diag[r][c]=r+c;
        }
    }
    int addgroupnum= 2*rownum-1;

    int extra_added_group_rightdown=addgroupnum;
    int extra_added_group_leftdown=addgroupnum;

    int holenum;
    cin >> holenum;
    while(holenum--){
        int b,c;
        cin >> b >> c;
        b--;
        c--;
        a[b][c]=-1;
        int drightdown=1;
        while(b+drightdown<rownum && c+drightdown<colnum){
            if(a[b+drightdown][c+drightdown]!=-1){
                rightdown_diag[b+drightdown][c+drightdown]= extra_added_group_rightdown;
            }
            drightdown++;
        }
        extra_added_group_rightdown++;

        int dleftdown=1;
        while(b+dleftdown<rownum && c-dleftdown>=0){
            if(a[b+dleftdown][c-dleftdown]!=-1){
                leftdown_diag[b+dleftdown][c-dleftdown]= extra_added_group_leftdown;
            }
            dleftdown++;
        }
        extra_added_group_leftdown++;

        rightdown_diag[b][c]=-1;
        leftdown_diag[b][c]=-1;
    }
    
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cout << rightdown_diag[r][c] << ' ';
        }
        cout << '\n';
    }
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cout << leftdown_diag[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << extra_added_group_leftdown << ' ' << extra_added_group_rightdown << '\n';
    MaximumFlow mf(max(extra_added_group_leftdown,extra_added_group_rightdown));
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            if(a[r][c]!=-1 && rightdown_diag[r][c]>=0 && leftdown_diag[r][c]>=0){
                mf.add_edge(rightdown_diag[r][c],leftdown_diag[r][c]);
            }
        }
    }
    
    cout << mf.flow() << '\n';

    return 0;
}