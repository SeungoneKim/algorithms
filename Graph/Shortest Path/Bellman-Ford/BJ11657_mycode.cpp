#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

struct Road{
    int from;
    int to;
    int cost;
};

long long dist[501];
long long infinity=1000000000;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex, edge;
    cin >> vertex >> edge;

    vector<Road>roadlist(edge);
    for(int k=0;k<edge;k++){
        cin >> roadlist[k].from >> roadlist[k].to >> roadlist[k].cost;
    }

    for(int k=2;k<=vertex;k++){
        dist[k]=infinity;
    }
    dist[1]=0;
    bool negative_cycle=false;
    for(int v=1;v<=vertex;v++){
        for(int e=0;e<edge;e++){
            int f=roadlist[e].from;
            int t=roadlist[e].to;
            int c=roadlist[e].cost;
            
            if(dist[t]>dist[f]+c && dist[f]!=infinity){
                dist[t]=dist[f]+c;
                if(v==vertex){
                    negative_cycle=true;
                    break;
                }
            }
        }
    }

    if(negative_cycle){
        cout << -1 << '\n';
        return 0;
    }

    for(int k=2;k<=vertex;k++){
        if(dist[k]!=infinity){
            cout << dist[k] << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }

    return 0;
}