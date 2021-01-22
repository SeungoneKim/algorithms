#include <iostream>

using namespace std;

int colorcost[1001][3]; // 0 is red, 1 is green, 2 is blue
int dp0[1001][3];
int dp1[1001][3];
int dp2[1001][3];
int bignum=10000000;

int main(){
    int n;
    cin >> n;

    for(int k=1;k<=n;k++){
        cin >> colorcost[k][0] >> colorcost[k][1] >> colorcost[k][2];
    }

    dp0[1][0]=colorcost[1][0];
    dp0[1][1]=bignum;
    dp0[1][2]=bignum;
    for(int k=2;k<=n;k++){
        dp0[k][1] = min(dp0[k-1][0],dp0[k-1][2])+colorcost[k][1];
        dp0[k][0] = min(dp0[k-1][1],dp0[k-1][2])+colorcost[k][0];
        dp0[k][2] = min(dp0[k-1][0],dp0[k-1][1])+colorcost[k][2];
    }
    dp1[1][1]=colorcost[1][1];
    dp1[1][0]=bignum;
    dp1[1][2]=bignum;
    for(int k=2;k<=n;k++){
        dp1[k][1] = min(dp1[k-1][0],dp1[k-1][2])+colorcost[k][1];
        dp1[k][0] = min(dp1[k-1][1],dp1[k-1][2])+colorcost[k][0];
        dp1[k][2] = min(dp1[k-1][0],dp1[k-1][1])+colorcost[k][2];
    }
    dp2[1][2]=colorcost[1][2];
    dp2[1][0]=bignum;
    dp2[1][1]=bignum;
    for(int k=2;k<=n;k++){
        dp2[k][1] = min(dp2[k-1][0],dp2[k-1][2])+colorcost[k][1];
        dp2[k][0] = min(dp2[k-1][1],dp2[k-1][2])+colorcost[k][0];
        dp2[k][2] = min(dp2[k-1][0],dp2[k-1][1])+colorcost[k][2];
    }

    int answ1= min(dp0[n][1],dp0[n][2]);
    int answ2= min(dp1[n][0],dp1[n][2]);
    int answ3= min(dp2[n][0],dp2[n][1]);

    int answ = min(answ1,min(answ2,answ3));

    cout << answ << '\n';

    return 0;
}