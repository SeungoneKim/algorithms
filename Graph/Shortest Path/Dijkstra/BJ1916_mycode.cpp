#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>>adjlist[1001];

int infinity=100000000;
int dist[1001];
bool visited[1001];

int main(){

    int vertex,edge;
    cin >> vertex >> edge;

    for(int k=0;k<edge;k++){
        int a,b,w;
        cin >> a >> b >>w;
        adjlist[a].push_back({b,w});
    }

    for(int k=1;k<=vertex;k++){
        dist[k]= infinity;
    }

    int init,destination;
    cin >> init >> destination;

    dist[init]=0;

    for(int k=1;k<vertex;k++){
        int m=infinity+1;
        int cur=-1;

        for(int i=1;i<=vertex;i++){
            if(dist[i]<m && visited[i]==false){
                m=dist[i];
                cur=i;
            }
        }
        visited[cur]=true;

        for(auto& a : adjlist[cur]){
            int next= a.first;
            int cost= a.second;

            if(dist[next]>dist[cur]+cost){
                dist[next]=dist[cur]+cost;
            }
        }
    }

    cout << dist[destination] << '\n';

    return 0;
}