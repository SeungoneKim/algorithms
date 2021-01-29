#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<vector<long long>> matrix;
const long long mod = 1000000009LL;
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
int dx[] = {-2,-1,1,2};
int dy[] = {1,0,0,1};
matrix make(int n, int m) {
    auto on = [&](int state, int col, int row) {
        return state & (1 << (col*n+row));
    };
    auto possible = [&](int state, int next) {
        for (int i=0; i<n; i++) {
            if (!on(next, 0, i)) continue;
            for (int k=0; k<4; k++) {
                if (i+dx[k] < 0 || i+dx[k] >= n) continue;
                if (on(state, dy[k], i+dx[k])) return false;
            }
        }
        return true;
    };
    int states = (1 << 2*n);
    matrix adj = vector<vector<long long>>(states, vector<long long>(states));
    for (int i=0; i<states; i++) {
        for (int j=0; j<(1<<n); j++) {
            if (possible(i, j)) {
                int k = (i >> n) | (j << n);
                adj[i][k] = 1;
            }
        }
    }
    return adj;
}
matrix pow(matrix a, int m) {
    int n = a.size();
    matrix ans = vector<vector<long long>>(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        ans[i][i] = 1;
    }
    while (m > 0) {
        if (m % 2 == 1) {
            ans = ans * a;
        }
        a = a * a;
        m /= 2;
    }
    return ans;
}
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        matrix adj = make(n, m);
        matrix ans = pow(adj, m);
        long long sum = 0;
        for (int i=0; i<(1<<(2*n)); i++) {
            sum = (sum + ans[0][i]) % mod;
        }
        cout << sum << '\n';
    }
    return 0;
}