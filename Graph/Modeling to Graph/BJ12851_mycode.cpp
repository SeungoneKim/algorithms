#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int dist[100001];
int answ[100001];

int main(){

    int x,y;
    cin >> x >> y;

    if(x==y){
        cout << 0 << '\n';
        cout << 1 << '\n';
        return 0;
    }

    memset(dist,-1,sizeof(dist));
    dist[x]=0;
    queue<int>q;
    q.push(x);

    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int next : {cur-1,cur+1,2*cur}){
            if(0<=next && next<=100000){
                if(dist[next]==-1 || dist[next]==dist[cur]+1){
                    if(dist[next]==-1){
                        dist[next]=dist[cur]+1;
                    }
                    answ[next]++;
                    q.push(next);
                }
            }
        }
    }

    cout << dist[y] << '\n';
    cout << answ[y] << '\n';

    return 0;
}