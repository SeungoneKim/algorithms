#include <iostream>
using namespace std;
int a[4001];
int d[301][4001];
int main() {
    int t, n, s, b;
    cin >> t >> n >> s >> b;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        a[x] += 1;
    }
    d[0][0] = 1;
    for (int i=1; i<=t; i++) {
        d[i][0] = 1;
        for (int j=1; j<=n; j++) {
            d[i][j] = 0;
            for (int k=0; k<=a[i]; k++) {
                if (j-k >= 0) {
                    d[i][j] += d[i-1][j-k];
                    d[i][j] %= 1000000;
                }
            }
        }
    }
    int ans = 0;
    for (int i=s; i<=b; i++) {
        ans += d[t][i];
        ans %= 1000000;
    }
    cout << ans << '\n';
    return 0;
}