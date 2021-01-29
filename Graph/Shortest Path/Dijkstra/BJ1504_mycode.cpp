#include <iostream>
#include <vector>

using namespace std;

vector <pair<int,int>> adjlist[1001];

long long dist[1001];
bool checker[1001];

int infinity = 100000000;

long long dijkstra(int start,int end, int vertex, int edge){
    // setting initial condition
    for(int k=1;k<=vertex;k++){
        dist[k] = infinity;
        checker[k] = false;
    }
    
    dist[start] = 0;
    
    // dijkstra algorithm
    for(int k=1;k<vertex;k++){
        
        //finding the vertex with the smallest dist value.
        long long min_of_left = infinity+1;
        int cur=0;
        for(int t=1;t<=vertex;t++){
            if(checker[t]==false && dist[t]<min_of_left){
                min_of_left = dist[t];
                cur = t;
            }
        }
        checker[cur] = true;
        
        //updating dist,checker array with edges connected to cur
        for(int p=0;p<adjlist[cur].size();p++){
            int next = adjlist[cur][p].first;
            int cost = adjlist[cur][p].second;
            
            if(dist[next]>dist[cur]+cost){
                dist[next] = dist[cur]+cost;
            }
        }
    }
    
    return dist[end];
}

int main(){
    
    // getting input
    int vertex, edge;
    cin >> vertex >> edge;
    
    for(int k=0,a,b,w;k<edge;k++){
        cin >> a >> b >>w;
        adjlist[a].push_back(make_pair(b, w));
        adjlist[b].push_back(make_pair(a, w));
    }
    
    int v1,v2;
    cin >> v1 >> v2;
    
   
    long long common = dijkstra(v1, v2, vertex, edge);
    long long firstansw = dijkstra(1,v1,vertex,edge)+dijkstra(v2, vertex, vertex, edge)+common;
    long long secondansw = dijkstra(1, v2, vertex, edge)+dijkstra(v1, vertex, vertex, edge)+common;
    
    long long answ = firstansw>secondansw?secondansw:firstansw;
    
    if(answ >=infinity)
        answ = -1;
    
    cout << answ << '\n';
    
    return 0;
}