#include <iostream>

using namespace std;

int dp[11];

int main()
{
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    for(int n=4; n<11 ; n++){
        dp[n] = dp[n-1] + dp[n-2] + dp[n-3];
    }     
    
    int testcasenum;
    cin >> testcasenum;
    
    while(testcasenum--){
        int testcase;
        cin >> testcase;
        cout << dp[testcase] << endl;
    }
    
    return 0;
}