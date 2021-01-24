#include <iostream>
#include <vector>

using namespace std;

int main(){

    int coin_type, goal;
    cin >> coin_type >> goal;

    vector<int>coinlist(coin_type);
    for(int k=0;k<coin_type;k++){
        cin >> coinlist[k];
    }

    int answ=0;
    
    for(int k=coin_type-1;k>=0;k--){
        while(goal-coinlist[k]>=0){
            goal-=coinlist[k];
            answ++;
        }
    }

    cout << answ << '\n';

    return 0;
}