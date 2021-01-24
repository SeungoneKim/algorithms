#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
tuple<int,int,int> bfs(vector<vector<int>> &a, int x, int y, int size) {
    int n = a.size();
    vector<tuple<int,int,int>> ans;
    vector<vector<int>> d(n, vector<int> (n, -1));
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    d[x][y] = 0;
    while (!q.empty()) {
        tie(x,y) = q.front();
        q.pop();
        for (int k=0; k<4; k++) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            if (0 <= nx && nx < n && 0 <= ny && ny < n && d[nx][ny] == -1) {
                bool ok = false;
                bool eat = false;
                // 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없고, 나머지 칸은 모두 지나갈 수 있다.
                if (a[nx][ny] == 0) {
                    ok = true;
                } else if (a[nx][ny] < size) { // 아기 상어는 자신의 크기보다 작은 물고기만 먹을 수 있다. 
                    ok = eat = true;
                } else if (a[nx][ny] == size) { // 크기가 같은 물고기는 먹을 수 없지만, 그 물고기가 있는 칸은 지나갈 수 있다.
                    ok = true;
                }
                if (ok) {
                    q.push(make_pair(nx,ny));
                    d[nx][ny] = d[x][y] + 1;
                    if (eat) {
                        ans.push_back(make_tuple(d[nx][ny],nx,ny));
                    }
                }
            }
        }
    }
    if (ans.empty()) {
        return make_tuple(-1,-1,-1);
    }
    sort(ans.begin(), ans.end());
    return ans[0];
}
int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    int x, y;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 9) {
                tie(x, y) = make_pair(i, j);
                a[i][j] = 0;
            }
        }
    }
    int ans = 0;
    int size = 2;
    int exp = 0;
    while (true) {
        int nx, ny, dist;
        tie(dist,nx,ny) = bfs(a, x, y, size);
        if (dist == -1) break;
        a[nx][ny] = 0;
        ans += dist;
        exp += 1;
        if (size == exp) {
            size += 1;
            exp = 0;
        }
        tie(x,y) = make_pair(nx,ny);
    }
    cout << ans << '\n';
    return 0;
}