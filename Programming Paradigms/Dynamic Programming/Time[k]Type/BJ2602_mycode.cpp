#include <iostream>
#include <string>
using namespace std;
int d[2][101][21];
int main() {
    string s;
    cin >> s;
    int m = s.size();
    s = " " + s;
    string a[2];
    cin >> a[0] >> a[1];
    int n = a[0].size();
    a[0] = " " + a[0];
    a[1] = " " + a[1];
    d[0][0][0] = d[1][0][0] = 1;
    for (int j=1; j<=m; j++) {
        for (int i=1; i<=n; i++) {
            for (int k=0; k<2; k++) {
                if (a[k][i] != s[j]) {
                    continue;
                }
                // d[k][i][j]
                for (int l=i-1; l>=0; l--) {
                    if (a[1-k][l] == s[j-1]) {
                        d[k][i][j] += d[1-k][l][j-1];
                    }
                }
            }
        }
    }
    int ans = 0;
    for (int k=0; k<2; k++) {
        for (int i=1; i<=n; i++) {
            ans += d[k][i][m];
        }
    }
    cout << ans << '\n';
}