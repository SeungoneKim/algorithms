#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

long long mod= 1000000007LL;

typedef vector<vector<long long>> matrix;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
            c[i][j] %= mod;
        }
    }
    return c;
}

int main(){

    long long n;
    cin >> n;

    if (n%2 == 1) {
        cout << 0 << '\n';
        return 0;
    }

    matrix ans(8,vector<long long>(8));
    matrix a(8,vector<long long>(8));
    

    for(int i=0;i<8;i++){
        ans[i][i]=1;
    }

    a[0][7] = 1;
    a[1][6] = 1;
    a[2][5] = 1;
    a[4][3] = 1;
    a[3][4] = a[3][7] = 1;
    a[6][1] = a[6][7] = 1;
    a[5][2] = 1;
    a[7][0] = a[7][3] = a[7][6] = 1;


    while(n>0){
        if(n%2 == 1){
            ans = ans*a;
        }
        a = a*a;
        n /=2;
    }

    long long sum=0;
    for(int i=0;i<7;i++){
        sum += ans[0][i];
    }
    sum %= mod;

    cout << sum << '\n';

    return 0;
}