#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<pair<int,int>>adjlist[1001];
priority_queue<int>dist[1001]; // dist
int number_of_elements_in_pq[1001];

priority_queue<pair<int,int>>pq;

int main(){

    int vertex, edge, k;
    cin >> vertex >> edge >> k;

    for(int t=1;t<=edge;t++){
        int a,b,w;
        cin >> a >> b >> w;
        adjlist[a].push_back({b,w});
    }

    dist[1].push(0);
    pq.push({-0,1});
    number_of_elements_in_pq[1]++;

    while(!pq.empty()){
        int cur_node= pq.top().second;
        int cur_sum_of_cost = -pq.top().first;
        pq.pop();

        for(auto& a : adjlist[cur_node]){
            int next_node = a.first;
            int next_cost = a.second;
            
            if(number_of_elements_in_pq[next_node]<k){
                dist[next_node].push(cur_sum_of_cost+next_cost);
                number_of_elements_in_pq[next_node]++;
                pq.push({-cur_sum_of_cost-next_cost,next_node});
            }
            else if(number_of_elements_in_pq[next_node]==k){
                if(dist[next_node].top()>cur_sum_of_cost+next_cost){
                    dist[next_node].pop();
                    dist[next_node].push(cur_sum_of_cost+next_cost);
                    pq.push({-cur_sum_of_cost-next_cost,next_node});
                }
            }
        }
    }

    for(int t=1;t<=vertex;t++){
        if(number_of_elements_in_pq[t]<k){
            cout << -1 << '\n';
        }
        else{
            cout << dist[t].top() << '\n';
        }
    }

    return 0;
}