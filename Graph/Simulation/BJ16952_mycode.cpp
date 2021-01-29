#include <iostream>
#include <cstring>
#include <tuple>
#include <queue>
#include <vector>
using namespace std;
int n;
int a[10][10];
pair<int,int> d[10][10][100][3]; // (x, y, num, piece)
queue<tuple<int,int,int,int>> q;
int dx1[] = {-2,-1,1,2,2,1,-1,-2};
int dy1[] = {1,2,2,1,-1,-2,-2,-1};
int dx2[] = {0,0,1,-1};
int dy2[] = {1,-1,0,0};
int dx3[] = {1,1,-1,-1};
int dy3[] = {1,-1,1,-1};
int main() {
    memset(d,-1,sizeof(d));
    cin >> n;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n*n; k++) {
                for (int l=0; l<3; l++) {
                    d[i][j][k][l] = make_pair(-1,-1);
                }
            }
        }
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            a[i][j] -= 1;
            if (a[i][j] == 0) {
                for (int k=0; k<3; k++) {
                    d[i][j][0][k] = make_pair(0,0);
                    q.push(make_tuple(i,j,0,k));
                }
            }
        }
    }
    pair<int,int> ans = make_pair(-1,-1);
    while (!q.empty()) {
        int x, y, num, piece;
        tie(x, y, num, piece) = q.front(); q.pop();
        auto &p = d[x][y][num][piece];
        if (num == n*n-1) {
            if (ans.first == -1 || ans > p) {
                ans = p;
            }
        }
        for (int i=0; i<3; i++) {
            if (piece == i) continue;
            auto np = make_pair(p.first+1, p.second+1);
            if (d[x][y][num][i].first == -1 || d[x][y][num][i] > np) {
                d[x][y][num][i] = np;
                q.push(make_tuple(x,y,num,i));
            }
        }
        if (piece == 0) { // knight
            for (int k=0; k<8; k++) {
                int nx = x+dx1[k];
                int ny = y+dy1[k];
                if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                    int next_num = num;
                    if (a[nx][ny] == num+1) {
                        next_num = num+1;
                    }
                    auto np = make_pair(p.first+1, p.second);
                    if (d[nx][ny][next_num][piece].first == -1 || d[nx][ny][next_num][piece] > np) {
                        d[nx][ny][next_num][piece] = np;
                        q.push(make_tuple(nx, ny, next_num, piece));
                    }
                }
            }
        } else if (piece == 1) { // rook
            for (int k=0; k<4; k++) {
                for (int l=1;; l++) {
                    int nx = x+dx2[k]*l;
                    int ny = y+dy2[k]*l;
                    if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                        int next_num = num;
                        if (a[nx][ny] == num+1) {
                            next_num = num+1;
                        }
                        auto np = make_pair(p.first+1, p.second);
                        if (d[nx][ny][next_num][piece].first == -1 || d[nx][ny][next_num][piece] > np) {
                            d[nx][ny][next_num][piece] = np;
                            q.push(make_tuple(nx, ny, next_num, piece));
                        }
                    } else {
                        break;
                    }
                }
            }
        } else { // bishop
            for (int k=0; k<4; k++) {
                for (int l=1;; l++) {
                    int nx = x+dx3[k]*l;
                    int ny = y+dy3[k]*l;
                    if (0 <= nx && nx < n && 0 <= ny && ny < n) {
                        int next_num = num;
                        if (a[nx][ny] == num+1) {
                            next_num = num+1;
                        }
                        auto np = make_pair(p.first+1, p.second);
                        if (d[nx][ny][next_num][piece].first == -1 || d[nx][ny][next_num][piece] > np) {
                            d[nx][ny][next_num][piece] = np;
                            q.push(make_tuple(nx, ny, next_num, piece));
                        }
                    } else {
                        break;
                    }
                }
            }
        }
    }
    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}


