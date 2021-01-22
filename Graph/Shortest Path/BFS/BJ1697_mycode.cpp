#include <iostream>
#include <queue>

using namespace std;
bool check[1000001];
int dist[1000001];
int can[3];
queue<int>q;

int main(){
    int now,target;
    cin >> now >> target;

    int lowerbound=0;
    int higherbound=100000;

    for(int k=lowerbound;k<=higherbound;k++){
        dist[k]=-1;
    }

    q.push(now);
    dist[now]=0;
    check[now]=true;

    while(!q.empty()){
        int num=q.front();
        q.pop();

        can[0]=num-1;
        can[1]=num+1;
        can[2]=2*num;

        for(int k=0;k<3;k++){
            if(lowerbound<=can[k]&&can[k]<=higherbound){
                if(!check[can[k]]){
                    dist[can[k]]=dist[num]+1;
                    check[can[k]]=true;
                    q.push(can[k]);
                }
            }
        }
    }

    cout << dist[target] << '\n';
    
    return 0;
}