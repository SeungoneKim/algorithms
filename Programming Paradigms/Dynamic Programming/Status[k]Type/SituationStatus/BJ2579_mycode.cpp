#include <iostream>

using namespace std;

int score[301];
int dp[301][2];
// status number is continuous stair number

int main(){
    int stairsize;
    cin >> stairsize;
    
    for(int k=1;k<=stairsize;k++){
        cin >> score[k];
    }
    
    dp[0][0] =0; dp[0][1]=0;
    
    dp[1][0] = score[1];
    dp[1][1] = 0;
    
    dp[2][0] = score[2];
    dp[2][1] = score[1]+score[2];
    
    //dp[n] is maximum scoresum including nth stair
    for(int k=3;k<=stairsize;k++){
        dp[k][0] = max(dp[k-2][0],dp[k-2][1])+score[k];
        dp[k][1] = dp[k-1][0]+score[k];
    }
    
    int answ = max(dp[stairsize][0],dp[stairsize][1]);
    
    cout << answ;
    
    return 0;
}