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

int peoplenum, worknum;

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
            if(dfs(pred[next])){
                pred[next]=x;
                return true;
            }
        }
        return false;
    }
    int flow(){
        int answ=0;
        for(int i=0;i<peoplenum;i++){
            for(int j=0;j<2;j++){
                if(dfs(i)){
                    answ+=1;
                }
            }
            fill(check.begin(),check.end(),false);
        }
        return answ;
    }
};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    cin >> peoplenum >> worknum;
    MaximumFlow mf(max(peoplenum,worknum));

    for(int i=0;i<peoplenum;i++){
        int query;
        cin >> query;
        while(query--){
            int tmp;
            cin >> tmp;
            mf.add_edge(i,tmp-1);
        }
    }

    int answ=0;
    answ= mf.flow();

    cout << answ << '\n';

    return 0;
}