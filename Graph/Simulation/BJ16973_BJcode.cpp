#include <iostream>
#include <tuple>
#include <queue>
using namespace std;
int a[1001][1001];
int d[1001][1001];
int s[1001][1001];
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
int sum(int x1, int y1, int x2, int y2) {
    return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> a[i][j];
            d[i][j] = -1;
        }
    }
    int h, w;
    cin >> h >> w;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(x1,y1));
    d[x1][y1] = 0;
    while (!q.empty()) {
        int x, y;
        tie(x, y) = q.front(); q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (1 <= nx && nx+h-1 <= n && 1 <= ny && ny+w-1 <= m) {
                if (sum(nx,ny,nx+h-1,ny+w-1) == 0) {
                    if (d[nx][ny] == -1) {
                        q.push(make_pair(nx,ny));
                        d[nx][ny] = d[x][y] + 1;
                    }
                }
            }
        }
    }
    cout << d[x2][y2] << '\n';
    return 0;
}

