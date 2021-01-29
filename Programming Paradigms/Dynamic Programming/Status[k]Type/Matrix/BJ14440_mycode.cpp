#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int mod=100;

void print(int x) {
    if (x < 10) {
        cout << 0;
    }
    cout << x << '\n';
}

typedef vector<vector<int>> matrix;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<int>(n));
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
    int x,y,a0,a1,n;
    cin >> x >> y >> a0 >> a1 >> n;

    if(n==0){
        print(a0);
    }
    else if(n==1){
        print(a1);
    }
    else{
        matrix ans(2,vector<int>(2));
        matrix a(2,vector<int>(2));

        a[0][0]=x; a[0][1]=y;
        a[1][0]=1; a[1][1]=0;

        ans[0][0]=a1;
        ans[1][0]=a0;

        n--;
        while(n>0){
            if(n%2 == 1){
                ans = ans*a;
            }
            a = a*a;
            n /=2;
        }

        int answ= ans[0][0]*a1 + ans[0][1]*a0;
        print(answ%mod);
    }

    return 0;
}
