#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> how_many_days(15);
vector<int> cost(15);
bool used[15];
int answ=0;

void backtrack(int index, int len, int totalsum){
    if(totalsum>answ){
        answ=totalsum;
        //cout << index << ' ' << totalsum << '\n';
    }

    for(int k=index+how_many_days[index];k<len;k++){
        if(!used[k] && k+how_many_days[k]<=len){
            used[k]=true;
            backtrack(k,len,totalsum+cost[k]);
            used[k]=false;
        }
    }
    return;
}


int main(){

    int avail;
    cin >> avail;

    how_many_days.resize(avail);
    cost.resize(avail);

    for(int k=0;k<avail;k++){
        cin >> how_many_days[k] >> cost[k];
    }

    for(int k=0;k<avail;k++){
        if(how_many_days[k]+k>avail){
            used[k]=true;
        }
    }

    for(int k=0;k<avail;k++){
        if(!used[k]){
            backtrack(k,avail,cost[k]);
        }
    }

    cout << answ << '\n';

    return 0;
}