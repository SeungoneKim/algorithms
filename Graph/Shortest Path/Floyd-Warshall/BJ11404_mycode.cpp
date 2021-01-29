#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int dist[101][101];
int infinity=100000000;

int main(){

    int vertex, edge;
    cin >> vertex >> edge;
    
    for(int k=1;k<=vertex;k++){
        for(int t=1;t<=vertex;t++){
            dist[k][t]=infinity;
        }
    }
    for(int k=1;k<=edge;k++){
        int a,b,w;
        cin >> a >> b >>w;

        if(dist[a][b]==infinity){
            dist[a][b]=w;
        }
        else{
            dist[a][b]= min(dist[a][b],w);
        }
    }

    for(int k=1;k<=vertex;k++){
        for(int i=1;i<=vertex;i++){
            for(int j=1;j<=vertex;j++){
                if(i==j) continue;
                if(dist[i][j] > dist[i][k] + dist[k][j] && dist[i][k]!=infinity && dist[k][j]!=infinity){
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
    }

    for(int k=1;k<=vertex;k++){
        for(int j=1;j<=vertex;j++){
            if(dist[k][j]==infinity || k==j){
                dist[k][j]=0;
            }
        }
    }

    for(int k=1;k<=vertex;k++){
        for(int j=1;j<=vertex;j++){
            cout << dist[k][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}