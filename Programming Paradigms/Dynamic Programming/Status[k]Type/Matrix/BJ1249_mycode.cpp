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

const long long mod=1234567891LL;

using matrix = vector<vector<long long>>;

matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}
matrix operator + (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c[i][j] = a[i][j] + b[i][j];
            c[i][j] %= mod;
        }
    }
    return c;
}
matrix init(int n) {
    matrix a(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        a[i][i] = 1;
    }
    return a;
}
matrix matrix_pow(matrix a, long long k) {
    if (k == 0) {
        return init(a.size());
    } else if (k % 2 == 0) {
        return matrix_pow(a*a, k/2);
    } else {
        return a * matrix_pow(a, k-1);
    }
}
matrix matrix_sum(matrix a, long long k) {
    int n = a.size();
    if (k == 0) {
        matrix ans(n, vector<long long>(n));
        return ans;
    } else if (k % 2 == 0) {
        return (init(n) + matrix_pow(a, k/2)) * matrix_sum(a, k/2);
    } else {
        return matrix_sum(a, k-1) + matrix_pow(a, k);
    }
}
void print(const matrix &a) {
    int n = a.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    int k;
    cin >> n >> k;

    matrix a(27,vector<long long>(27));
    for(int i=0;i<27;i++){
        a[i][i]=i;
        if(i+1<27)
            a[i][i+1]=26-i;
    }

    matrix d;
    if(n%2==0){
        d= matrix_sum(a,n/2);
    }
    else{
        d= matrix_sum(a,(n-1)/2);
    }

    long long answ=0;
    for(int i=0;i<=k;i++){
        answ = (answ+d[0][i]) % mod;
    }
    answ = answ*2LL;
    answ %= mod;
    if(n%2==1){
        d= matrix_pow(a, (n+1)/2);
        for(int i=0;i<=k;i++){
            answ = (answ+d[0][i]) % mod;
        }
    }

    cout << answ << '\n';
    
    return 0;
}