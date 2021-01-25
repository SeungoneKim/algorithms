#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
vector<int>up;
vector<int>down;
int matrix[2][401];
int dp[401][401][401];
int n;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    up.push_back(0);
    down.push_back(0);
    cin >> n;
    for(int k=1;k<=n;k++){
        int a;
        cin >> a;
        if(a!=0){
            up.push_back(a);
        }
    }
    for(int k=1;k<=n;k++){
        int a;
        cin >> a;
        if(a!=0){
            down.push_back(a);
        }
    }

    int up_size=up.size();
    int down_size=down.size();

    for(int k=1;k<=n;k++){
        for(int i=1;i<up_size;i++){
            for(int j=1;j<down_size;j++){
                if(i>k) continue;
                if(j>k) continue;
                int cur = dp[k-1][i-1][j-1] + up[i]*down[j];
                if(j-1>=0 && k-1>=i){
                    cur = max(cur,dp[k-1][i][j-1]);
                }
                if(i-1>=0 && k-1>=j){
                    cur= max(cur,dp[k-1][i-1][j]);
                }
                dp[k][i][j]=cur;
            }
        }
    }
    
    cout << dp[n][up_size-1][down_size-1] << '\n';

    return 0;
}