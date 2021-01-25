#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

long long dp[11][100001];
long long sum[11];
const long long mod = 1000000007LL;
vector<int>divisors[100001];

int main(){

    int n,k;
    cin >> n >> k;

    for(int i=1;i<=k;i++){
        for(int j=i*2;j<=k;j+=i){
            divisors[j].push_back(i);
        }
    }

    for(int t=1;t<=k;t++){
        dp[1][t]=1;
    }
    sum[1]=k;
    for(int i=2;i<=n;i++){
        for(int j=1;j<=k;j++){
            dp[i][j] = sum[i-1];
            for(int div : divisors[j]){
                dp[i][j] -= dp[i-1][div];
                dp[i][j] %=mod;
                dp[i][j] +=mod;
                dp[i][j] %=mod;
            }
            sum[i] += dp[i][j];
            sum[i] %= mod;
        }
    }

    cout << sum[n] << '\n';

    return 0;
}