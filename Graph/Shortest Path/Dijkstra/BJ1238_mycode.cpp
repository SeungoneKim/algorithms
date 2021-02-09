#include <bits/stdc++.h>

using namespace std;

int vertex,edge,destination;
vector<pair<int,int>>adjlist[1001];

bool check[1001];
int dist[1001];
int answ[1001];
int back[1001];

int INF = 100000000;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> vertex >> edge >> destination;

    for(int i=0;i<edge;i++){
        int from,to,howmuch;
        cin >> from >> to >> howmuch;

        adjlist[from].push_back({to,howmuch});
    }

    for(int i=1;i<=vertex;i++){
        priority_queue<pair<int,int>>pq;
        for(int j=1;j<=vertex;j++){
            dist[j]=INF;
        }
        memset(check,false,sizeof(check));
        pq.push({0,i});
        dist[i]=0;

        while(!pq.empty()){
            int cur = pq.top().second;
            pq.pop();
            if(!check[cur]){
                check[cur] = true;

                for(auto& a : adjlist[cur]){
                    int next = a.first;
                    int cost = a.second;
                    if(dist[cur]+cost<dist[next]){
                        dist[next] = dist[cur]+cost;
                        pq.push({-dist[next],next});
                    }
                }
            }
        }
        if(i!=destination){
            answ[i] = dist[destination];
        }
        else{
            for(int j=1;j<=vertex;j++){
                back[j]= dist[j];
            }
        }
    }
    
    int max_cost=0;
    for(int i=1;i<=vertex;i++){
        if(answ[i]+back[i]>max_cost){
            max_cost=answ[i]+back[i];
        }
    }

    cout << max_cost << '\n';

    return 0;
}