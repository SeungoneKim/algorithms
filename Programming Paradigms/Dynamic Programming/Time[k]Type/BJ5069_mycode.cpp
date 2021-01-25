#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <climits>

using namespace std;

// Global arrays
int dp[15][29][29]; // (x,y)-> [14+x][14+y]
int dx[6]={1,0,-1,-1,0,1};
int dy[6]={0,-1,-1,0,1,1};
// Global variables

// functions

// main function
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[0][14][14]=1;
    for(int k=1;k<=14;k++){
        for(int i=0;i<29;i++){
            for(int j=0;j<29;j++){
                for(int l=0;l<6;l++){
                    int x=i+dx[l];
                    int y=j+dy[l];
                    if(0<=x && x<29 && 0<=y && y<29){
                        dp[k][i][j] += dp[k-1][x][y];
                    }
                }
            }
        }
    }

    int tc;
    cin>> tc;

    while(tc--){
        int a;
        cin >> a;
        cout << dp[a][14][14] << '\n';
    }


    return 0;
}