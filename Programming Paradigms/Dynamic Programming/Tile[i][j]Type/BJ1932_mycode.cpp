#include <iostream>

using namespace std;

int triangle[501][501];
int dp[501][501];

int main(){
    int size;
    cin >> size;

    for(int k=1;k<=size;k++){
        for(int t=1;t<=k;t++){
            cin >> triangle[k][t];
        }
    }

    dp[1][1] = triangle[1][1];
    for(int k=2;k<=size;k++){
        for(int t=1;t<=k;t++){
            if(t==1)
                dp[k][t] = dp[k-1][t]+triangle[k][t];
            else if(t==k)
                dp[k][t] = dp[k-1][t-1]+triangle[k][t];
            else
                dp[k][t] = max(dp[k-1][t-1],dp[k-1][t])+triangle[k][t];
        }
    }

    int answ=0;
    for(int t=1;t<=size;t++){
        answ = max(answ,dp[size][t]);
    }

    cout << answ << '\n';

    return 0;
}