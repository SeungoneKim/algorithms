#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
string a[1500];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
bool wcheck[1500][1500];
bool scheck[1500][1500];
int main() {
    int n, m;
    cin >> n >> m;
    int sx,sy,ex,ey;
    sx=sy=ex=ey=-1;
    queue<pair<int,int>> swan, nswan, water, nwater;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (int j=0; j<m; j++) {
            if (a[i][j] == 'L') {
                if (sx == -1) {
                    sx = i;
                    sy = j;
                } else {
                    ex = i;
                    ey = j;
                }
                a[i][j] = '.';
            }
            if (a[i][j] == '.') {
                water.push(make_pair(i,j));
                wcheck[i][j] = true;
            }
        }
    }
    swan.push(make_pair(sx,sy));
    scheck[sx][sy] = true;
    for (int i=0;; i++) {
        while (!water.empty()) {
            int x = water.front().first;
            int y = water.front().second;
            water.pop();
            a[x][y] = '.';
            for (int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (wcheck[nx][ny]) continue;
                if (a[nx][ny] == '.') {
                    water.push(make_pair(nx,ny));
                    wcheck[nx][ny] = true;
                } else {
                    nwater.push(make_pair(nx,ny));
                    wcheck[nx][ny] = true;
                }
            }
        }
        while (!swan.empty()) {
            int x = swan.front().first;
            int y = swan.front().second;
            swan.pop();
            for (int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if (scheck[nx][ny]) continue;
                if (a[nx][ny] == '.') {
                    swan.push(make_pair(nx,ny));
                    scheck[nx][ny] = true;
                } else {
                    nswan.push(make_pair(nx,ny));
                    scheck[nx][ny] = true;
                }
            }
        }
        if (scheck[ex][ey]) {
            cout << i << '\n';
            break;
        }
        water = nwater;
        swan = nswan;
        nwater = queue<pair<int,int>>();
        nswan = queue<pair<int,int>>();
    }
    return 0;
}