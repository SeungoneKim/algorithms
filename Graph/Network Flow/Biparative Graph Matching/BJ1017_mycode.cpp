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

int nn;
vector<int>answ;

bool checkprime(int num){
    if(num<2) return false;

    for(int k=2;k*k<=num;k++){ // sqrt(n)을 사용하지 않음
        if(num%k==0)
            return false;
    }

    return true;
}

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

    cin >> nn;
    vector<int>a(nn);
    for(int i=0;i<nn;i++){
        cin >> a[i];
    }

    for(int k=1;k<nn;k++){
        if(checkprime(a[0]+a[k])){
            vector<int>odd;
            vector<int>even;
            for(int t=1;t<nn;t++){
                if(t==k) continue;
                if(a[t]%2==0){
                    even.push_back(a[t]);
                }
                else{
                    odd.push_back(a[t]);
                }
            }
            if(even.size()!=odd.size()) continue;

            int m=even.size();
            MaximumFlow mf(m);
            for(int i=0;i<m;i++){
                for(int p=0;p<m;p++){
                    if(checkprime(even[i]+odd[p])){
                        mf.add_edge(i,p);
                    }
                }
            }

            if(mf.flow()==even.size()){
                answ.push_back(a[k]);
            }
        }
    }
    if(answ.empty()){
        cout << -1 << '\n';
    }
    else{
        sort(answ.begin(),answ.end());
        for(int i=0;i<answ.size();i++){
            cout << answ[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}