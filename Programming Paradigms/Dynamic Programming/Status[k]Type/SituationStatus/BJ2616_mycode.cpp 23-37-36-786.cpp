#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int arr[50001];
int sumarr[50001];
int dp[50001][4];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len;
    cin >> len;
    for(int k=1;k<=len;k++){
        cin >> arr[k];
        sumarr[k]=sumarr[k-1]+arr[k];
    }

    int people_max;
    cin >> people_max;

    for(int j=1;j<=3;j++){
        for(int k=people_max*j;k<=len;k++){
            dp[k][j]=dp[k-1][j];
            dp[k][j]=max(dp[k][j],dp[k-people_max][j-1]+sumarr[k]-sumarr[k-people_max]);
        }
    }

    cout << dp[len][3] << '\n';

    return 0;
}