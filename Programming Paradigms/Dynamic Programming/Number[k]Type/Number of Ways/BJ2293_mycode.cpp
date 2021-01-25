#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int coin[101];
int dp[10001];

int main(){

    int cointype, totalsum;
    cin >> cointype >> totalsum;

    for(int k=1;k<=cointype;k++){
        cin >> coin[k];
    }

    dp[0]=1;
    for(int j=1;j<=cointype;j++){
        for(int k=1;k<=totalsum;k++){
            if(k-coin[j]>=0){
                dp[k] += dp[k-coin[j]];
            }
        }
    }

    cout << dp[totalsum] << '\n';

    return 0;
}