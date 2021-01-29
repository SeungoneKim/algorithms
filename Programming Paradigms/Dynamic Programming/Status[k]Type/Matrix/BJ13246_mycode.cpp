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

typedef vector<vector<int>> matrix;
const int mod = 1000;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<int>(n));
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
    matrix c(n, vector<int>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            c[i][j] = a[i][j] + b[i][j];
            c[i][j] %= mod;
        }
    }
    return c;
}
matrix init(int n) {
    matrix a(n, vector<int>(n));
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
        matrix ans(n, vector<int>(n));
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

    int n;
    long long b;
    cin >> n >> b;

    matrix mat(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> mat[i][j];
        }
    }

    matrix answ = matrix_sum(mat,b);

    print(answ);

    return 0;
}