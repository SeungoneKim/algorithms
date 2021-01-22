#include <iostream>
#include <queue>

using namespace std;

bool check[3001][3001]; // [num of emoticons][num of emoticons in clipboard]
int dist[3001][3001];
queue<pair<int,int>>q;

pair<int,int> numbers[3];

int main(){

    int target;
    cin >> target;

    check[1][0]=true;
    q.push({1,0});
    dist[1][0]=0;

    while(!q.empty()){
        int curemo=q.front().first;
        int clipemo=q.front().second;
        q.pop();

        numbers[0]= {curemo,curemo};
        numbers[1]= {curemo+clipemo,clipemo};
        numbers[2]= {curemo-1,clipemo};

        for(int k=0;k<3;k++){
            if(1<=numbers[k].first&&numbers[k].first<=3000){
                if(!check[numbers[k].first][numbers[k].second]){
                    check[numbers[k].first][numbers[k].second]=true;
                    dist[numbers[k].first][numbers[k].second]=dist[curemo][clipemo]+1;
                    q.push(numbers[k]);
                }
            }
        }
    }
    int answ=10000000;
    for(int k=1;k<=target;k++){
        if(dist[target][k]<answ)
            answ=dist[target][k];
    }

    cout << answ << '\n';

    return 0;
}