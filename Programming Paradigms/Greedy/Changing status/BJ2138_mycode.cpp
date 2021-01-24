#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;

vector<int> init_state(100000);
vector<int> final_state(100000);
vector<int> test_state(100000);

void change(int cur){
    for(int k=cur-1;k<=cur+1;k++){
        if(0<=k && k<num){
            test_state[k]=1-test_state[k];
        }
    }
}

bool check(int cur){
    if(test_state[cur]==final_state[cur]){
        return true;
    }
    return false;
}

int main(){

    // getting input
    cin >> num;

    init_state.resize(num);
    final_state.resize(num);
    test_state.resize(num);

    for(int k=0;k<num;k++){
        char x;
        cin >> x;
        init_state[k]=x-'0';
    }
    test_state=init_state;

    for(int k=0;k<num;k++){
        char x;
        cin >> x;
        final_state[k]=x-'0';
    }

    // greedy algorithm
    // note that kth switch is decided by k-1th bulb.

    // we first consider not changing the first switch which connects 0,1 bulb.
    int answ=0;
    for(int k=1;k<num;k++){
        if(!check(k-1)){
            change(k);
            answ++;
        }
    }

    if(test_state[num-1]==final_state[num-1]){
        cout << answ << '\n';
        return 0;
    }
    else{
        answ=1;
        test_state=init_state;
    }


    // we next consider changing the first switch
    test_state[0]=1-test_state[0];
    test_state[1]=1-test_state[1];
    for(int k=1;k<num;k++){
        if(!check(k-1)){
            change(k);
            answ++;
        }
    }
    if(test_state[num-1]==final_state[num-1]){
        cout << answ << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}