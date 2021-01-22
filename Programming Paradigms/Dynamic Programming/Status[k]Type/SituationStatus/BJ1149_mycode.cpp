#include <iostream>

using namespace std;

int colorcost[1001][3]; // 0 is red, 1 is green, 2 is blue
int dp[1001][3];

int main(){
    int house_num;
    cin >> house_num;

    for(int k=1;k<=house_num;k++){
        cin >> colorcost[k][0] >> colorcost[k][1] >> colorcost[k][2];
    }

    dp[1][0]=colorcost[1][0]; dp[1][1]=colorcost[1][1]; dp[1][2]=colorcost[1][2];
    for(int k=2;k<=house_num;k++){
        dp[k][0]= min(dp[k-1][1],dp[k-1][2])+colorcost[k][0];
        dp[k][1]= min(dp[k-1][0],dp[k-1][2])+colorcost[k][1];
        dp[k][2]= min(dp[k-1][0],dp[k-1][1])+colorcost[k][2];
    }

    int answ=min(min(dp[house_num][0],dp[house_num][1]),dp[house_num][2]);

    cout << answ << '\n';

    return 0;
}