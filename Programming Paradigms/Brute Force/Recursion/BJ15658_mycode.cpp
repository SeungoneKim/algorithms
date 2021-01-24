#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int>numbers;

int operators[4];

int maxansw=-1000000000;
int minansw=1000000000;

void backtrack(int idx, int goalidx, int sum, int op1, int op2, int op3, int op4){
    if(idx==goalidx-1){
        if(sum<minansw) minansw=sum;
        if(sum>maxansw) maxansw=sum;
        return;
    }
    if(op1>0){
        int nextsum = sum + numbers[idx+1];
        backtrack(idx+1,goalidx,nextsum,op1-1,op2,op3,op4);
    }
    if(op2>0){
        int nextsum = sum - numbers[idx+1];
        backtrack(idx+1,goalidx,nextsum,op1,op2-1,op3,op4);
    }
    if(op3>0){
        int nextsum = sum * numbers[idx+1];
        backtrack(idx+1,goalidx,nextsum,op1,op2,op3-1,op4);
    }
    if(op4>0){
        int nextsum = sum / numbers[idx+1];
        backtrack(idx+1,goalidx,nextsum,op1,op2,op3,op4-1);
    }
}

int main(){

    int n;
    cin >> n;

    numbers.resize(n);
    for(int k=0;k<n;k++){
        cin >> numbers[k];
    }

    for(int k=0;k<4;k++){
        cin >> operators[k];
    }


    backtrack(0,n,numbers[0],operators[0],operators[1],operators[2],operators[3]);

    cout << maxansw << '\n';
    cout << minansw << '\n';

    return 0;
}