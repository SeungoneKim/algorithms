#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <queue>
using namespace std;
struct MaximumFlow {
    int n;
    int source, sink;
    vector<vector<int>> graph;
    vector<bool> check;
    vector<int> pred;
    MaximumFlow(int n) : n(n) {
        graph.resize(n);
        check.resize(n);
        pred.resize(n,-1);
    };
    void add_edge(int u, int v) {
        graph[u].push_back(v);
    }
    bool dfs(int x) {
        if (x == -1) return true;
        for (int next : graph[x]) {
            if (check[next]) continue;
            check[next] = true;
            if (dfs(pred[next])) {
                pred[next] = x;
                return true;
            }
        }
        return false;
    }
    int flow() {
        int ans = 0;
        for (int i=0; i<n; i++) {
            fill(check.begin(),check.end(),false);
            if (dfs(i)) {
                ans += 1;
            }
        }
        return ans;
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    vector<vector<int>> a(n+1, vector<int>(n+1,0));
    vector<vector<int>> r(n+1, vector<int>(n+1,0));
    vector<vector<int>> c(n+1, vector<int>(n+1,0));
    int rn=0;
    int cn=0;
    while (m--) {
        int u,v;
        cin >> u >> v;
        a[u][v] = 1;
    }
    for (int i=1; i<=n; i++) {
        int x = i;
        int y = 1;
        while (x <= n && y <= n) {
            if (a[x][y] == 0) {
                if (x-1 <= 0 || y-1 <= 0 || a[x-1][y-1] == 1) {
                    r[x][y] = ++rn;
                } else if (a[x-1][y-1] == 0) {
                    r[x][y] = r[x-1][y-1];
                }
            }
            x++;
            y++;
        }
        x = i;
        y = 1;
        while (x >= 1 && y <= n) {
            if (a[x][y] == 0) {
                if (x+1 > n || y-1 <= 0 || a[x+1][y-1] == 1) {
                    c[x][y] = ++cn;
                } else if (a[x+1][y-1] == 0) {
                    c[x][y] = c[x+1][y-1];
                }
            }
            x--;
            y++;
        }
        if (i == 1) continue;
        x = 1;
        y = i;
        while (x <= n && y <= n) {
            if (a[x][y] == 0) {
                if (x-1 <= 0 || y-1 <= 0 || a[x-1][y-1] == 1) {
                    r[x][y] = ++rn;
                } else if (a[x-1][y-1] == 0) {
                    r[x][y] = r[x-1][y-1];
                }
            }
            x++;
            y++;
        }
        x = n;
        y = i;
        while (x >= 1 && y <= n) {
            if (a[x][y] == 0) {
                if (x+1 > n || y-1 <= 0 || a[x+1][y-1] == 1) {
                    c[x][y] = ++cn;
                } else if (a[x+1][y-1] == 0) {
                    c[x][y] = c[x+1][y-1];
                }
            }
            x--;
            y++;
        }
    }
    /*
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%3d",r[i+1][j+1]);
        }
        puts("");
    }
    puts("");
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%3d",c[i+1][j+1]);
        }
        puts("");
    }
    */
    MaximumFlow mf(max(rn,cn));
    cout << rn << ' ' << cn << '\n';
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (r[i][j] > 0 && c[i][j] > 0 && a[i][j] == 0) {
                mf.add_edge(r[i][j]-1,c[i][j]-1);
            }
        }
    }
    printf("%d\n",mf.flow());
    return 0;
}