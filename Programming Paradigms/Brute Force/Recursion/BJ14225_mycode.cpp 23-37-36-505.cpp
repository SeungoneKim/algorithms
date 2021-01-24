#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool check[20*100000+1];

vector<int> numbers;
vector<int> checker;

void backtrack(int idx, int goalidx, int sum){
    if(idx==goalidx){
        if(!check[sum]){
            check[sum]=true;
            // checker.push_back(sum);
        }
        return;
    }
    int nextsum= sum+numbers[idx];
    backtrack(idx+1,goalidx,nextsum);
    int nextsum2= sum;
    backtrack(idx+1,goalidx,nextsum2);
}

int main(){

    int len;
    cin >> len;

    numbers.resize(len);
    for(int k=0;k<len;k++){
        cin >> numbers[k];
    }

    backtrack(0,len,0);

    for(int k=1;k<=20*100000;k++){
        if(!check[k]){
            cout << k << '\n';
            return 0;
        }
    }

    return 0;
}