#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int dp[4000][1<<3];

int main(){

    dp[0][0]=1;
    for(int i=0;i<4000;i++){
        for(int j=0;j<(1<<4);j++){
            if(dp[i][j]>0){
                // we first put 1*2 block
                if(((j&1)==0) && i%4!=3)
                    dp[i+2][j>>2] += dp[i][j];
                // next we put 2*1 block
                if((i/4)<1000)
                    dp[i+1][(j>>1)|4] += dp[i][j];
            }
        }
    }

    for(int i=0;i<20;i++){
        for(int j=0;j<(1<<4);j++){
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }

    int tc;
    cin >> tc;
    int m=0;
    while(tc--){
        cin >> m;
        cout << dp[4*m-1][0] << '\n';
    }


    return 0;
}