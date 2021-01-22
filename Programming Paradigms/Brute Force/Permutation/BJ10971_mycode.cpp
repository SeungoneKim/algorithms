#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cost[11][11];
vector<int>road(11);

int main(){

    int n;
    cin >> n;

    road.resize(n);

    for(int k=1;k<=n;k++){
        for(int t=1;t<=n;t++){
            cin >> cost[k][t];
        }
    }

    for(int k=0;k<n;k++){
        road[k]=k+1;
    }

    int answ=1000000000;
    do{
        int tmp=0;
        bool flg=false;
        for(int k=0;k<n-1;k++){
            if(cost[road[k]][road[k+1]]==0){
                flg=true;
                break;
            }
            tmp += cost[road[k]][road[k+1]];
        }
        if(flg==true){
            continue;
        }
        if(cost[road[n-1]][road[0]]==0) continue;
        tmp += cost[road[n-1]][road[0]];
        if(tmp<answ) answ=tmp;

    }while(next_permutation(road.begin(),road.end()));

    cout << answ << '\n';

    return 0;
}