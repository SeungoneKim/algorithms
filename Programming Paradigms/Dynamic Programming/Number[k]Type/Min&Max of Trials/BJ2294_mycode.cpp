#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dp[10001];
int coin[101];
int infinity=100000000;

int main(){

    int cointype,totalsum;
    cin >> cointype >> totalsum;
    for(int k=1;k<=cointype;k++){
        cin >> coin[k];
    }
    for(int k=1;k<=totalsum;k++){
        dp[k]=infinity;
    }

    dp[0]=0;
    for(int j=1;j<=cointype;j++){
        for(int k=1;k<=totalsum;k++){
            if(k-coin[j]>=0){
                if(dp[k-coin[j]]+1<dp[k]){
                    dp[k]=dp[k-coin[j]]+1;
                }
            }
        }
    }
    
    if(dp[totalsum]==infinity){
        cout << -1 << '\n';
    }
    else{
        cout << dp[totalsum] << '\n';
    }

    return 0;
}