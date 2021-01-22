#include <iostream>

using namespace std;

int sticker[2][100001];
int dp[100001][4]; // 0 is not taking off sticker, 1 is up, 2 is down.
// 3 is max value between 0~2

int main(){
    int tc;
    cin >> tc;

    while(tc--){
        int num;
        cin >> num;

        for(int k=1;k<=num;k++){
            cin >> sticker[0][k];
        }
        for(int k=1;k<=num;k++){
            cin >> sticker[1][k];
        }

        dp[1][1]=sticker[0][1];
        dp[1][2]=sticker[1][1];
        dp[1][3]=max(dp[1][1],dp[1][2]);

        for(int k=2;k<=num;k++){
            dp[k][0] = dp[k-1][3];
            dp[k][1] = max(dp[k-1][0],dp[k-1][2])+sticker[0][k];
            dp[k][2] = max(dp[k-1][0],dp[k-1][1])+sticker[1][k];
            dp[k][3] = max(dp[k][1],dp[k][2]);
        }

        cout << dp[num][3] << '\n';
    }

    return 0;
}