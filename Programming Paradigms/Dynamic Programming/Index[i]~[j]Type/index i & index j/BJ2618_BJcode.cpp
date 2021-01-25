#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
const int inf = 1000000000;
int dist[1010][1010];
int d[1010][1010];
int v[1010][1010];
int a[1010][2];
int main() {
    ios_base::sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    n += 2;
    a[1][0] = 1;
    a[1][1] = 1;
    a[2][0] = m;
    a[2][1] = m;
    for (int i=3; i<=n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    for (int i=1; i<=n; i++) {
        for (int j=i; j<=n; j++) {
            dist[i][j] = abs(a[i][0]-a[j][0]) + abs(a[i][1]-a[j][1]);
            dist[j][i] = dist[i][j];
            d[i][j] = d[j][i] = inf;
        }
    }
    d[1][2] = 0;
    for (int i=3; i<=n; i++) {
        for (int j=1; j<i-1; j++) {
            if (j != 2) {
                if (d[i][i-1] > d[j][i-1] + dist[j][i]) {
                    d[i][i-1] = d[j][i-1] + dist[j][i];
                    v[i][i-1] = j;
                }
                d[j][i] = d[j][i-1] + dist[i-1][i];
                v[j][i] = i-1;
            }
            if (j >= 2) {
                if (d[i-1][i] > d[i-1][j] + dist[j][i]) {
                    d[i-1][i] = d[i-1][j] + dist[j][i];
                    v[i-1][i] = j;
                }
                d[i][j] = d[i-1][j] + dist[i-1][i];
                v[i][j] = i-1;
            }
        }
    }
    int ans = inf;
    int x, y;
    for (int i=1; i<=n; i++) {
        if (d[n][i] < ans) {
            ans = d[n][i];
            x = n;
            y = i;
        }
        if (d[i][n] < ans) {
            ans = d[i][n];
            x = i;
            y = n;
        }
    }
    stack<int> s;
    for (int i=0; i<n-2; i++) {
        int prev = v[x][y];
        if (x > y) {
            s.push(1);
            x = prev;
        } else {
            s.push(2);
            y = prev;
        }
    }
    cout << ans << '\n';
    while (!s.empty()) {
        cout << s.top() << '\n';
        s.pop();
    }
    return 0;
}