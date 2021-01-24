#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

int dist[101];
int nextslot[101];
queue<int>q;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ladder, snake;
    cin >> ladder >> snake;

    for(int k=1;k<=100;k++){
        nextslot[k]=k;
    }
    for(int k=0;k<ladder;k++){
        int x,y;
        cin >> x >> y;
        nextslot[x]=y;
    }
    for(int k=0;k<snake;k++){
        int x,y;
        cin >> x >> y;
        nextslot[x]=y;
    }

    memset(dist,-1,sizeof(dist));

    dist[1]=0;
    q.push(1);

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int k=1;k<=6;k++){
            int future= nextslot[cur+k];
            if(1<=future && future<=100){
                if(dist[future]==-1){
                    dist[future]=dist[cur]+1;
                    q.push(future);
                }
            }
        }
    }

    cout << dist[100] << '\n';

    return 0;
}