#include <iostream>
#include <vector>

using namespace std;

vector<int> v(10001);
int dp[1001];

int main(){
    int n;
    cin >> n;

    for(int k=1;k<=n;k++){
        cin >> v[k];
    }
    //initilaization
    for(int k=1;k<=n;k++){
        dp[k]=v[k];
    }

    for(int k=2;k<=n;k++){
        for(int t=1;t<k;t++){
            if(dp[k]>dp[t]+v[k-t])
                dp[k]=dp[t]+v[k-t];
        }
    }

    cout << dp[n] << '\n';

    return 0;
}