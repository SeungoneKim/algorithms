#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> adjlist[10001];
bool visited[10001];
int startv,endv;

bool dfs(int x,int maxw){
    if(x==endv) return true;
    int cur =x;
    visited[x]=true;

    for(int k=0;k<adjlist[x].size();k++){
        int next=adjlist[x][k].first;
        int nextw = adjlist[x][k].second;
        if(visited[next]==false){
            if(nextw>=maxw){
                if(dfs(next, maxw)){
                    return true;
                }
            }
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex,edge;
    cin >> vertex >> edge;

    int tmpw=0;
    for(int k=1;k<=edge;k++){
        int a,b,w;
        cin >> a >> b >> w;
        
            adjlist[a].push_back({b,w});
            adjlist[b].push_back({a,w});
        
        if(w>tmpw) tmpw=w;
    }

    cin >> startv >> endv;

    long long left=0;
    long long right=tmpw+1;
    long long mid = 0;
    long long answ=0;

    while(left<=right){
        long long mid= (left+right)/2;
        bool sol= dfs(startv, mid);
        for(int k=1;k<=vertex;k++){
            visited[k]=false;
        }
        if(sol){
            if(mid>answ) answ=mid;
            left=mid+1;
        }
        else{
            right=mid-1;
        }
    }

    cout << answ << '\n';

    return 0;
}