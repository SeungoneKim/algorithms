#include <iostream>

using namespace std;

int dp[100001][3]; // 0 is not using nth row, 1 is leftside, 2 is rightside.
int mod = 9901;

int main(){
    int rownum;
    cin >> rownum;

    dp[1][0]=1;dp[1][1]=1;dp[1][2]=1;

    for(int k=2;k<=rownum;k++){
        dp[k][0] = (dp[k-1][0]+dp[k-1][1]+dp[k-1][2])%mod;
        dp[k][1] = (dp[k-1][0]+dp[k-1][2])%mod;
        dp[k][2] = (dp[k-1][0]+dp[k-1][1])%mod;
    }

    int answ = (dp[rownum][0]+dp[rownum][1]+dp[rownum][2])%mod;
    cout << answ << '\n';

    return 0;
}