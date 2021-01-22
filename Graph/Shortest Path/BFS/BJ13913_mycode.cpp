#include <iostream>
#include <queue>
#include <stack>

using namespace std;
bool check[200001];
int dist[200001];
int can[3];
int before[200001];
queue<int>q;
stack<int>s;

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
                    before[can[k]]=num;
                    q.push(can[k]);
                }
            }
        }
    }

    cout << dist[target] << '\n';
    s.push(target);
    for(int k=1;k<=dist[target];k++){
        int a= s.top();
        a=before[a];
        s.push(a);
    }
    for(int k=1;k<=dist[target];k++){
        int a = s.top();
        cout << a << ' ';
        s.pop();
    }
    cout << target << '\n';
    
    return 0;
}