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
int cownum, homenum;

// Global arrays


// functions
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
        for(int i=0;i<cownum;i++){
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
    
    cin >> cownum >> homenum;
    MaximumFlow mf(max(cownum,homenum));

    for(int i=0;i<cownum;i++){
        int tmp;
        cin >> tmp;
        while(tmp--){
            int w;
            cin >> w;
            mf.add_edge(i,w-1);
        }
    }

    cout << mf.flow() << '\n';

    return 0;
}