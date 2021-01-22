#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct node{
    int to;
    int cost;
    node(int t, int d): to(t), cost(d){}
};

vector<node> adjlist[100001];
queue<int> q;
int dist[100001];
bool checker[100001];

void bfs(int s){
    memset(dist,0,sizeof(dist));
    memset(checker,false,sizeof(checker));
    
    checker[s]=true;
    dist[s]=0;
    q.push(s);
    
    while(!q.empty()){
        int k = q.front();
        q.pop();
        
        for(int t=0;t<adjlist[k].size();t++){
            node &e =adjlist[k][t];
            int p = e.to;
            if(!checker[p]){
                checker[p]=true;
                dist[p]=dist[k]+e.cost;
                q.push(p);
            }
        }
    }
}

int main(){
    int n;
    scanf("%d",&n);
    
    for(int k=1;k<=n;k++){
        int cur=0;
        scanf("%d", &cur);
        while(true){
        int v,e;
        scanf("%d", &v);
        
        if(v==-1) break;
        
        scanf("%d", &e);
        
        adjlist[cur].push_back(node(v,e));
        }
    }
    
    bfs(1);
    
    int most=dist[1];
    int num=1;
    for(int k=1;k<=n;k++){
        if(dist[k]>most){
            most = dist[k];
            num =k;
        }
    }
    
    bfs(num);
    
    most=dist[num];
    for(int k=1;k<=n;k++){
        if(dist[k]>most){
            most = dist[k];
            num=k;
        }
    }
    printf("%d",dist[num]);
    
    return 0;
}