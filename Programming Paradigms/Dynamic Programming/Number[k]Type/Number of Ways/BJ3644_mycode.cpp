#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int dp[10001];
int ans[10001];

int main(){

    dp[1]=0;
    dp[2]=2;
    dp[3]=3;
    for(int k=4;k<=10000;k++){
        dp[k] = dp[k-1]+dp[k-2];
    }
    

    int n;
    while(cin >> n){
        cout << dp[n] << '\n';
    }


    return 0;
}