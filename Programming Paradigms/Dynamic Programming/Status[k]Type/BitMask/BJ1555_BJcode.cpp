#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <set>

using namespace std;

set<int>dp[1<<6];

bool checkprime(int num){
    if(num<2) return false;

    for(int k=2;k*k<=num;k++){ // sqrt(n)을 사용하지 않음
        if(num%k==0)
            return false;
    }

    return true;
}

set<int> solve(vector<int>&a, int mask){
    set<int>& answ = dp[mask];
    if(answ.size()>0){
        return answ;
    }
    if(mask==0){
        return answ;
    }
    int n = a.size();
    for(int i=0;i<(1<<n);i++){
        int first= i&mask;
        int second = (~first)&mask;
        if(first==0 || second==0) continue;

        solve(a,first);
        solve(a,second);

        for(int x:dp[first]){
            for(int y:dp[second]){
                if(x!=0){
                    answ.insert(y/x);
                }
                if(y!=0){
                    answ.insert(x/y);
                }
                answ.insert(x+y);
                answ.insert(x-y);
                answ.insert(y-x);
                answ.insert(x*y);
            }
        }
    }
    return answ;
}

int main(){

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        dp[1<<i].insert(arr[i]);
    }

    auto ans= solve(arr,(1<<n)-1);

    int answ_min=-1;
    int answ_max=-1;

    for(auto& x: ans){
        if(checkprime(x)){
            if(answ_min==-1){
                answ_min=x;
            }
            answ_max=x;
        }
    }
    if(answ_min==-1){
        cout << -1 << '\n';
    }
    else{
        cout << answ_min << '\n';
        cout << answ_max << '\n';
    }

    return 0;
}