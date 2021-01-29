#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int dp[1001];

int main(){

    int n;
    cin >> n;

    dp[0]=1; dp[1]=-1; dp[2]=1; dp[3]=-1; dp[4]=1;
    for(int k=5;k<=n;k++){
        if(dp[k-1]==-1 || dp[k-3]==-1 || dp[k-4]==-1){
            dp[k]=1;
        }
        else{
            dp[k]=-1;
        }
    }

    if(dp[n]==1){
        cout << "SK" << '\n';
    }
    else{
        cout << "CY" << '\n';
    }


    return 0;
}