#include <iostream>
#include <deque>

using namespace std;
bool check[200001];
int dist[200001];
int can[3];
deque<int>d;

int main(){
    int now,target;
    cin >> now >> target;

    int lowerbound=0;
    int higherbound=100000;

    for(int k=lowerbound;k<=higherbound;k++){
        dist[k]=-1;
    }

    d.push_back(now);
    dist[now]=0;
    check[now]=true;

    while(!d.empty()){
        int num=d.front();
        d.pop_front();

        can[0]=num-1;
        can[1]=num+1;
        can[2]=num*2;

        if(lowerbound<=can[2]&&can[2]<=higherbound){
            if(!check[can[2]]){
                dist[can[2]]=dist[num];
                check[can[2]]=true;
                d.push_front(can[2]);
            }
        }

        for(int k=0;k<2;k++){
            if(lowerbound<=can[k]&&can[k]<=higherbound){
                if(!check[can[k]]){
                    dist[can[k]]=dist[num]+1;
                    check[can[k]]=true;
                    d.push_back(can[k]);
                }
            }
        }
    }

    cout << dist[target] << '\n';
    
    return 0;
}