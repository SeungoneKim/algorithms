#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge{
    int start,end,weight;
    bool operator < (const Edge& other)const{
        return weight < other.weight;
    }
};

int parent[10001];

int answ=0;

int find(int x){
    if(x == parent[x])
        return x;
    else{
        int p = find(parent[x]);
        parent[x] = p;
        return p;
    }
}

void unionfunc(int x, int y){
    int c = find(x);
    int d = find(y);
    
    parent[d]=c;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    //getting input
    int vertex, edge;
    cin >> vertex >> edge;
    
    //initialization
    for(int k=1;k<=vertex;k++){
        parent[k]=k;
    }
    
    vector<Edge>adjlist(edge);
    //getting input
    for(int k=0;k<edge;k++){
        cin >> adjlist[k].start >> adjlist[k].end >> adjlist[k].weight;
    }
    
    //sorting the adjlist before using union-find ds. -> sorts based on weight
    sort(adjlist.begin(),adjlist.end());
    
    //using union-find ds.
    for(int k=0;k<edge;k++){
        int a = adjlist[k].start;
        int b = adjlist[k].end;
        int x = find(a);
        int y = find(b);
        
        if(x!=y){
            answ+= adjlist[k].weight;
            unionfunc(a, b);
        }
    }
    cout << answ << '\n';
    
    return 0;
}