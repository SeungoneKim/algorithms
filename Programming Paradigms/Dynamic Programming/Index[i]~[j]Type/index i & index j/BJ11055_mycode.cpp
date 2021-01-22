#include <iostream>

using namespace std;
int sequence[1001];
int dp[1001];

int main(){
    int len;
    cin >> len;

    for(int k=1;k<=len;k++){
        cin >> sequence[k];
    }

    for(int k=1;k<=len;k++){
        dp[k] = sequence[k];
    }

    for(int k=2;k<=len;k++){
        for(int t=1;t<k;t++){
            if(sequence[t]<sequence[k])
                dp[k] = max(dp[k],dp[t]+sequence[k]);
        }
    }

    int answ=dp[1];
    for(int k=2;k<=len;k++){
        answ = max(answ,dp[k]);
    }

    cout << answ << '\n';

    return 0;
}