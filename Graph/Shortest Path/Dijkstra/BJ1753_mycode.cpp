#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int infinity= 1000000000;

vector<pair<int,int>>adjlist[20001];
priority_queue<pair<int,int>>pq;
int dist[20001];
bool check[20001];

int main(){

    int vertex, edge;
    cin >> vertex >> edge;

    int start_node;
    cin >> start_node;

    for(int k=1;k<=edge;k++){
        int a,b,w;
        cin >> a >> b >> w;

        adjlist[a].push_back({b,w});
    }

    for(int k=1;k<=vertex;k++){
        dist[k]=infinity;
    }
    dist[start_node]=0;
    pq.push({-0,start_node});

    while(!pq.empty()){
        int cur_sum_of_cost= -pq.top().first;
        int cur_node = pq.top().second;
        check[cur_node]=true;
        pq.pop();

        for(auto&a : adjlist[cur_node]){
            int next_node = a.first;
            int next_cost = a.second;

            if(!check[next_node]){
                if(dist[next_node]>dist[cur_node]+next_cost){
                    dist[next_node]=dist[cur_node]+next_cost;
                    pq.push({-dist[cur_node]-next_cost,next_node});
                }
            }
        }
    }

    for(int t=1;t<=vertex;t++){
        if(dist[t]==infinity){
            cout << "INF" << '\n';
        }
        else{
            cout << dist[t] << '\n';
        }
    }

    return 0;
}