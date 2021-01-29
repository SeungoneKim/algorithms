#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
char a[111][111];
bool c[111][111];
bool key[111];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
int main() {
    int t;
    scanf("%d",&t);
    while (t--) {
        int n, m;
        memset(a,0,sizeof(a));
        scanf("%d %d",&n,&m);
        for (int i=2; i<n+2; i++) {
            scanf("%s",a[i]+2);
        }
        n += 4;
        m += 4;
        for (int i=0; i<n; i++) {
            a[i][0] = '*';
            a[i][1] = '.';
            a[i][m-2] = '.';
            a[i][m-1] = '*';
        }
        for (int j=1; j<m-1; j++) {
            a[0][j] = '*';
            a[1][j] = '.';
            a[n-2][j] = '.';
            a[n-1][j] = '*';
        }
        memset(key,false,sizeof(key));
        char temp[111];
        scanf("%s",temp);
        int len = strlen(temp);
        if (temp[0] != '0') {
            for (int i=0; i<len; i++) {
                key[temp[i]-'a'] = true;
            }
        }
        int ans = 0;
        memset(c,false,sizeof(c));
        queue<pair<int,int>> q;
        queue<pair<int,int>> door[26];
        q.push(make_pair(1,1));
        c[1][1] = true;
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int k=0; k<4; k++) {
                int nx = x+dx[k];
                int ny = y+dy[k];
                if (c[nx][ny]) {
                    continue;
                }
                char w = a[nx][ny];
                if (w == '*') {
                    continue;
                }
                c[nx][ny] = true;
                if (w == '.') {
                    q.push(make_pair(nx,ny));
                } else if (w == '$') {
                    ans += 1;
                    q.push(make_pair(nx,ny));
                } else if (w >= 'A' && w <= 'Z') {
                    if (key[w-'A']) {
                        q.push(make_pair(nx,ny));
                    } else {
                        door[w-'A'].push(make_pair(nx,ny));
                    }
                } else if (w >= 'a' && w <= 'z') {
                    q.push(make_pair(nx,ny));
                    if (!key[w-'a']) {
                        key[w-'a'] = true;
                        while (!door[w-'a'].empty()) {
                            q.push(door[w-'a'].front());
                            door[w-'a'].pop();
                        }
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}