#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int arr[101];
int dp[101][100001];
int mod=10000003;

int gcd(int s, int b){
    if(s==0) return b;

    int k =s;
    s= b%s;
    b=k;

    return gcd(s,b);
}

int main(){

    int n;
    cin >> n;

    for(int k=1;k<=n;k++){
        cin >> arr[k];
    }
    
    dp[1][arr[1]]=1;
    for(int k=2;k<=n;k++){
        dp[k][arr[k]]=1;
        for(int t=1;t<=100000;t++){
            if(dp[k-1][t]>0){
                dp[k][t] += dp[k-1][t];
                dp[k][t] %= mod;
                dp[k][gcd(t,arr[k])] += dp[k-1][t];
                dp[k][t] %= mod;
            }
        }
    }

    cout << dp[n][1]%mod << '\n';

    return 0;
}