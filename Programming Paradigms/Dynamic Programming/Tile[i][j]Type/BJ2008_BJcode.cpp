#include <iostream>
#include <cstring>
using namespace std;
int a[501];
int d[501][501];
int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> m >> n;
    int start, end, del, add;
    cin >> start >> end >> del >> add;
    start -= 1;
    end -= 1;
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        a[i] -= 1;
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<m; j++) {
            d[i][j] = 1000000000;
        }
    }
    for (int i=0; i<m; i++) {
        if (i == start) {
            d[0][i] = 0;
        } else {
            d[0][i] = abs(start - i) * add;
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=0; j<m; j++) {
            for (int k=0; k<m; k++) {
                if (k == j && (a[i] == k || a[i]+1 == k)) {
                    if (d[i][j] > d[i-1][k] + del) {
                        d[i][j] = d[i-1][k] + del;
                    }
                } else if ((k <= a[i] && a[i] <= j-1) || (j <= a[i] && a[i] <= k-1)) {
                    if (d[i][j] > d[i-1][k] + (abs(k-j)-1)*add) {
                        d[i][j] = d[i-1][k] + (abs(k-j)-1)*add;
                    }
                } else {
                    if (d[i][j] > d[i-1][k] + abs(k-j)*add) {
                        d[i][j] = d[i-1][k] + abs(k-j)*add;
                    }
                }
            }
        }
    }
    cout << d[n][end] << '\n';
    return 0;
}