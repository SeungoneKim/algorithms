#include <iostream>

using namespace std;

int dp[1000001];

int topdown(int n){
    if(n==1) return 0;
    if(dp[n]>0) return dp[n];

    int answ = topdown(n-1)+1;
    if(n%2==0){
        if(answ > topdown(n/2)+1)
            answ = topdown(n/2)+1;
    }
    if(n%3==0){
        if(answ > topdown(n/3)+1)
            answ = topdown(n/3)+1;
    }
    dp[n] = answ;

    return dp[n];
}

int main(){
    int n;
    cin >> n;

    int ans = topdown(n);

    cout << ans << '\n';

    return 0;
}