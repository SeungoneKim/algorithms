#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

struct Road{
    int init;
    int destination;
    int cost;
};

long long infinity=1000000000;
long long dist[505];
bool negative_cycle=false;

int main(){

    int tc;
    cin >> tc;

    while(tc--){
        int vertex,edge,wormhole;
        cin >> vertex >> edge >> wormhole;

        vector<Road>roadlist(2*edge+wormhole);
        for(int k=0;k<2*edge;k+=2){
            int a,b,w;
            cin >> a >> b >> w;
            roadlist[k].init=a;
            roadlist[k].destination=b;
            roadlist[k].cost=w;
            roadlist[k+1].init=b;
            roadlist[k+1].destination=a;
            roadlist[k+1].cost=w;
        }
        for(int k=2*edge;k<2*edge+wormhole;k++){
            int a,b,w;
            cin >> a >> b >> w;
            roadlist[k].init=a;
            roadlist[k].destination=b;
            roadlist[k].cost=-w;
        }

        for(int k=2;k<=vertex;k++){
            dist[k]= infinity;
        }
        dist[1]=0;
        for(int v=1;v<=vertex;v++){
            for(int e=0;e<2*edge+wormhole;e++){
                int f=roadlist[e].init;
                int t=roadlist[e].destination;
                int c=roadlist[e].cost;
                if(dist[t]>dist[f]+c){
                    dist[t]=dist[f]+c;
                    if(v==vertex){
                        negative_cycle=true;
                    }
                }
            }
        }

        if(negative_cycle){
            cout << "YES" <<'\n';
        }
        else{
            cout << "NO" << '\n';
        }
        
        for(int k=1;k<=vertex;k++){
            dist[k]=0;
        }
        negative_cycle=false;
    }

    return 0;
}