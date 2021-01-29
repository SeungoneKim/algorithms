#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>>adjlist[10001];
vector<pair<int,int>>reverse_adjlist[10001];
queue<int> q;
queue<int>backtrack;
int indegree[10001];
int max_dist[10001];
int howmuch[10001];

bool inside_rq[10001];

int main(){

    int vertex,edge;
    cin >> vertex >> edge;

    for(int k=1;k<=edge;k++){
        int a,b,w;
        cin >> a >> b >> w;

        adjlist[a].push_back({b,w});
        reverse_adjlist[b].push_back({a,w});
        indegree[b]++;
    }
    int init,dest;
    cin >> init >> dest;
    
    for(int k=1;k<=vertex;k++){
        if(indegree[k]==0){
            q.push(k);
        }
    }

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(auto& a : adjlist[cur]){
            int nextt= a.first;
            int cost=a.second;

            indegree[nextt]--;
            if(max_dist[nextt]<max_dist[cur]+cost){
                max_dist[nextt]=max_dist[cur]+cost;
            }

            if(indegree[nextt]==0){
                q.push(nextt);
            }
        }
    }

    cout << max_dist[dest] << '\n';
    
    backtrack.push(dest);
    int answ=0;
    while(!backtrack.empty()){
        int cur= backtrack.front();
        backtrack.pop();
        inside_rq[cur]=false;
        
        for(auto& a : reverse_adjlist[cur]){
            int nextt=a.first;
            int cost=a.second;

            if(max_dist[cur]==max_dist[nextt]+cost){
                answ++;
                if(!inside_rq[nextt]){
                    inside_rq[nextt]=true;
                    backtrack.push(nextt);
                }
            }
        }
    }

    cout << answ << '\n';

    return 0;
}