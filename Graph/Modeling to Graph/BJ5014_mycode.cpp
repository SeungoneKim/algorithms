#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int howmuch[10000001];
bool check[10000001];
int infinity=100000000;
queue<int>q;

int main(){

    int building_height,goal,init;
    cin >> building_height >> init >> goal;

    int howmuch_up,howmuch_down;
    cin >> howmuch_up >> howmuch_down;

    for(int k=1;k<=building_height;k++){
        howmuch[k]=infinity;
    }

    howmuch[init]=0;
    check[init]=true;
    q.push(init);
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        int next= cur+howmuch_up;
        if(0<=next && next<=building_height){
            if(!check[next]){
                check[next]=true;
                howmuch[next]=howmuch[cur]+1;
                q.push(next);
            }
        }

        next= cur-howmuch_down;
        if(0<=next && next<=building_height){
            if(!check[next]){
                check[next]=true;
                howmuch[next]=howmuch[cur]+1;
                q.push(next);
            }
        }
    }

    if(howmuch[goal]==infinity){
        cout << "use the stairs" << '\n';
    }
    else{
        cout << howmuch[goal] << '\n';
    }


    return 0;
}