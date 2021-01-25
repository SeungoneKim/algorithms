#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;
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

    long long b;
    cin >> b;

    if(b<=1){
        cout << b << '\n';
        return 0;
    }
    b-=1;

    matrix ans = {{1,0},{0,1}};
    matrix a={{1,1},{1,0}};

    while(b>0){
        if(b%2 == 1){
            ans = ans*a;
        }
        a = a*a;
        b /=2;
    }

    cout << ans[0][0] << '\n';

    return 0;
}