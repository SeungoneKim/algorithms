#include<iostream>

using namespace std;

long long dp[91][2];

int main(){
    dp[1][0] = 0;
    dp[1][1] = 1;
    
    int digitnum;
    cin >> digitnum;
    
    for(int k=2;k<=digitnum;k++){
        dp[k][0] += dp[k-1][0];
        dp[k][0] += dp[k-1][1];
        dp[k][1] += dp[k-1][0];
    }
    
    long long answ;
    answ = dp[digitnum][0] + dp[digitnum][1];
    
    cout << answ << endl;
    
    return 0;
}