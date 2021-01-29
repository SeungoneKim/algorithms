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
int eating_shark_num;

// Global arrays
vector<int>SIZE(50);
vector<int>VELOCITY(50);
vector<int>INT(50);

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
        for(int i=0;i<eating_shark_num;i++){
            for(int j=0;j<2;j++){
                fill(check.begin(),check.end(),false);
                if(dfs(i)){
                    answ+=1;
                }
            }
        }
        return answ;
    }
};

// main function
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> eating_shark_num;
    MaximumFlow mf(eating_shark_num);

    for(int i=0;i<eating_shark_num;i++){
        cin >> SIZE[i] >> VELOCITY[i] >> INT[i];
    }

    for(int i=0;i<eating_shark_num;i++){
        for(int j=0;j<eating_shark_num;j++){
            if(i==j) continue;
            if(SIZE[i]==SIZE[j] && VELOCITY[i]==VELOCITY[j] && INT[i]==INT[j]){
                if(i<j){
                    mf.add_edge(i,j);
                }
            }
            else if(SIZE[i]>=SIZE[j] && VELOCITY[i]>=VELOCITY[j] && INT[i]>=INT[j]){
                mf.add_edge(i,j);
            }
        }
    }

    cout << eating_shark_num-mf.flow() << '\n';

    return 0;
}