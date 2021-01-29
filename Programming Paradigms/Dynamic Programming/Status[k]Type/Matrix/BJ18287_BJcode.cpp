#include <iostream>
#include <vector>
using namespace std;
const long long mod = 1000000007;
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
int main() {
    int n, m;
    cin >> n >> m;
    matrix ans(m, vector<long long>(m));
    matrix even(m, vector<long long>(m));
    matrix odd(m, vector<long long>(m));
    matrix a(m, vector<long long>(m));
    for (int i=0; i<m; i++) {
        ans[i][i] = 1;
        odd[i][i] = 1;
        if (i-1 >= 0) {
            odd[i][i-1] = 1;
            even[i][i-1] = 1;
        }
        if (i+1 < m) {
            odd[i][i+1] = 1;
            even[i][i+1] = 1;
        }
    }
    n -= 1;
    a = even * odd;
    int p = n/2;
    while (p > 0) {
        if (p % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        p /= 2;
    }
    if (n % 2 == 1) {
        ans = ans * even;
    }
    long long sum = 0;
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            sum += ans[i][j];
            sum %= mod;
        }
    }
    cout << sum << '\n';
    return 0;
}