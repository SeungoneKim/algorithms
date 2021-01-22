#include <iostream>

using namespace std;

int arr[100001];
int dp[100001];

int main(){
    int n;
    cin >> n;

    for(int k=1;k<=n;k++){
        cin >> arr[k];
    }

    dp[1]=arr[1];
    for(int k=2;k<=n;k++){
        dp[k]= max(dp[k-1]+arr[k],arr[k]);
    }

    int asw=dp[1];
    for(int k=2;k<=n;k++){
        asw=max(dp[k],asw);
    }

    cout << asw << '\n';

    return 0;
}