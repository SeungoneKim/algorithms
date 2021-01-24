#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int num;
    cin >> num;

    vector<int> cost(num);
    for(int k=0;k<num;k++){
        cin >> cost[k];
    }

    sort(cost.begin(),cost.end());

    int answ=0;
    for(int k=1;k<num;k++){
        cost[k]=cost[k-1]+cost[k];
    }
    for(int k=0;k<num;k++){
        answ += cost[k];
    }

    cout << answ << '\n';

    return 0;
}