#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[101];
long long dp[101][21];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len;
    cin >> len;
    for(int k=1;k<=len;k++){
        cin >> arr[k];
    }

    dp[1][arr[1]]=1;
    for(int k=2;k<len;k++){
        for(int t=0;t<=20;t++){
            if(t-arr[k]>=0){
                if(dp[k-1][t-arr[k]]!=0){
                    dp[k][t]+= dp[k-1][t-arr[k]];
                }
            }
            if(t+arr[k]<=20){
                if(dp[k-1][t+arr[k]]!=0){
                    dp[k][t]+=dp[k-1][t+arr[k]];
                }
            }
        }
    }

    cout << dp[len-1][arr[len]] << '\n';


    return 0;
}