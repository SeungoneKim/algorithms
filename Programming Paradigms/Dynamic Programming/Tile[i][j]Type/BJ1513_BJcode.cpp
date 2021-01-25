#include <iostream>
#include <cstring>
using namespace std;
int position[51][51];
int d[51][51][51][51];
int ans[51];
const int mod = 1000007;
int main() {
    int r, c, n;
    cin >> r >> c >> n;
    memset(position,-1,sizeof(position));
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        position[x][y] = i;
    }
    d[1][0][0][0] = 1;
    for (int i=1; i<=r; i++) {
        for (int j=1; j<=c; j++) {
            if (position[i][j] == -1) {
                d[i][j][0][0] += d[i-1][j][0][0] + d[i][j-1][0][0];
                d[i][j][0][0] %= mod;
            }
            for (int l=1; l<=n; l++) {
                if (position[i][j] == -1) {
                    for (int k=0; k<n; k++) {
                        d[i][j][k][l] += d[i-1][j][k][l] + d[i][j-1][k][l];
                        d[i][j][k][l] %= mod;
                    }
                } else {
                    int m = position[i][j];
                    if (l == 1) {
                        d[i][j][m][l] += d[i-1][j][0][0] + d[i][j-1][0][0];
                        d[i][j][m][l] %= mod;
                    } else {
                        for (int k=0; k<m; k++) {
                            d[i][j][m][l] += d[i-1][j][k][l-1] + d[i][j-1][k][l-1];
                            d[i][j][m][l] %= mod;
                        }
                    }
                }
            }
        }
    }
    for (int i=0; i<=n; i++) {
        for (int k=0; k<max(n,1); k++) {
            ans[i] += d[r][c][k][i];
            ans[i] %= mod;
        }
        printf("%d ",ans[i]);
    }
    printf("\n");
    return 0;
}