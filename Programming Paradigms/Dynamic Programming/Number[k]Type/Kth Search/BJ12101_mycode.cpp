#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <climits>

using namespace std;

long long dp[11];
vector<int>answ;

void printer(int n,long long k){
    if(n==0) return;

    if(dp[n-1]>=k){
        answ.push_back(1);
        printer(n-1,k);
    }
    else if(dp[n-1]+dp[n-2]>=k){
        answ.push_back(2);
        printer(n-2,k-dp[n-1]);
    }
    else{
        answ.push_back(3);
        printer(n-3,k-dp[n-1]-dp[n-2]);
    }
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=10;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }

    int n;
    long long k;
    cin >> n >> k;
    if(k>dp[n]){
        cout << -1 << '\n';
        return 0;
    }
    printer(n,k);
    int m=answ.size();
    for(int i=0;i<m;i++){
        cout << answ[i];
        if(i!=m-1)
            cout << "+";
    }
    cout << '\n';

    return 0;
}