#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int weight[101];
int price[101];

int dp[101][100001];

int main(){

    int how_many_stuff,weight_max;
    cin >> how_many_stuff >> weight_max;

    for(int k=1;k<=how_many_stuff;k++){
        cin >> weight[k] >> price[k];
    }

    for(int k=1;k<=how_many_stuff;k++){
        for(int j=1;j<=weight_max;j++){
            dp[k][j]=dp[k-1][j];
            if(j-weight[k]>=0){
                dp[k][j]=max(dp[k][j],dp[k-1][j-weight[k]]+price[k]);
            }
        }
    }

    int answ=0;
    for(int k=1;k<=weight_max;k++){
        if(dp[how_many_stuff][k]>answ){
            answ= dp[how_many_stuff][k];
        }
    }

    cout << answ << '\n';

    return 0;
}