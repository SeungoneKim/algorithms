#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int dist[200][200];
int dr[6]={-2,-2,0,0,2,2};
int dc[6]={-1,1,-2,2,-1,1};

queue<pair<int,int>>q;

int main(){

    int size;
    cin >> size;

    int startr, startc, goalr, goalc;
    cin >> startr >> startc >> goalr >> goalc;

    memset(dist,-1,sizeof(dist));

    dist[startr][startc]=0;
    q.push({startr,startc});

    while(!q.empty()){
        int curr=q.front().first;
        int curc=q.front().second;
        q.pop();

        for(int k=0;k<6;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            if(0<=nextr && nextr<size && 0<=nextc && nextc<size){
                if(dist[nextr][nextc]==-1){
                    dist[nextr][nextc]=dist[curr][curc]+1;
                    q.push({nextr,nextc});
                }
            }
        }
    }

    cout << dist[goalr][goalc] << '\n';

    return 0;
}