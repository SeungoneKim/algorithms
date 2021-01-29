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
int state_map[10][2][2];
int main() {
    long long n;
    int k;
    cin >> n >> k;
    int kk = max(k, 1);
    int state_num = 0;
    for (int a=0; a<kk; a++) {
        for (int b=0; b<2; b++) {
            for (int c=0; c<2; c++) {
                state_map[a][b][c] = state_num++;
            }
        }
    }
    int size = kk * 2 * 2;
    matrix ans(size, vector<long long>(size));
    matrix mat(size, vector<long long>(size));
    for (int i=0; i<size; i++) {
        ans[i][i] = 1;
    }
    for (int a=0; a<kk; a++) {
        for (int b=0; b<2; b++) {
            for (int c=0; c<2; c++) {
                int state = state_map[a][b][c];
                if (k > 0) {
                    mat[state][state_map[(a+1)%k][0][c]] += 1;
                }
                if (b == 0) {
                    mat[state][state_map[a][1][c]] += 1;
                }
                mat[state][state_map[a][0][1]] += 1;
            }
        }
    }
    while (n > 0) {
        if (n % 2 == 1) {
            ans = ans * mat;
        }
        mat = mat * mat;
        n /= 2;
    }
    long long sum = ans[0][state_map[0][0][1]] + ans[0][state_map[0][1][1]];
    sum %= mod;
    cout << sum << '\n';
    return 0;
}

