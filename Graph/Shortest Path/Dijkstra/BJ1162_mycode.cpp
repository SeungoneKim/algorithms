#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

long long infinity= 1000000000LL*50000LL;

vector<pair<int,long long>>adjlist[10001];
priority_queue<tuple<long long,int,int>>pq;

long long dist[10001][21];
bool check[10001][21];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex,edge;
    int k;
    cin >> vertex >> edge >> k;

    for(int t=1;t<=edge;t++){
        int a,b,w;
        cin >> a >> b >> w;
        adjlist[a].push_back({b,w});
        adjlist[b].push_back({a,w});
    }

    for(int i=1;i<=vertex;i++){
        for(int t=0;t<=k;t++){
            dist[i][t]=infinity;
        }
    }

    dist[1][0]=0;
    pq.push(make_tuple(-0,-0,1));

    while(!pq.empty()){

        int cur_node = get<2>(pq.top());
        long long cur_cost_sum = -get<0>(pq.top());
        int erased_num = -get<1>(pq.top());
        pq.pop();
        check[cur_node][erased_num]=true;

        for(auto& a : adjlist[cur_node]){
            int next_node = a.first;
            long long next_cost = a.second;
            if(!check[next_node][erased_num+1]){
                if(erased_num+1<=k){
                    if(dist[next_node][erased_num+1]>dist[cur_node][erased_num]){
                        dist[next_node][erased_num+1] = dist[cur_node][erased_num];
                        pq.push(make_tuple(-dist[next_node][erased_num+1],-(erased_num+1),next_node));
                    }
                }
            }
            if(!check[next_node][erased_num]){
                if(dist[next_node][erased_num]>dist[cur_node][erased_num]+next_cost){
                    dist[next_node][erased_num]=dist[cur_node][erased_num]+next_cost;
                    pq.push(make_tuple(-dist[next_node][erased_num],-erased_num,next_node));
                }
            }
            
        }
    }

    long long answ=infinity;
    for(int p=0;p<=k;p++){
        if(answ>dist[vertex][p] && check[vertex][p]==true){
            answ=dist[vertex][p];
        }
    }
    if(answ==infinity){
        answ=-1;
    }

    cout << answ << '\n';

    return 0;
}