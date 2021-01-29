#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;
const int MAX = 100111;
vector<pair<int,int>> a[MAX];
int parent[MAX];
bool check[MAX];
int depth[MAX];
int p[MAX][18];
int len[MAX];
int len_min[MAX][18];
int len_max[MAX][18];
pair<int,int> lca(int u, int v) {
    if (depth[u] < depth[v]) {
        swap(u,v);
    }
    int ans_min = 10000000;
    int ans_max = 0;
    int log = 1;
    for (log=1; (1<<log) <= depth[u]; log++);
    log-=1;
    for (int i=log; i>=0; i--) {
        if (depth[u] - (1<<i) >= depth[v]) {
            if (ans_min > len_min[u][i]) {
                ans_min = len_min[u][i];
            }
            if (ans_max < len_max[u][i]) {
                ans_max = len_max[u][i];
            }
            u = p[u][i];
        }
    }
    //printf("! %d %d\n",u,v);
    //printf("@ %d %d\n",ans_min,ans_max);
    if (u == v) {
        return make_pair(ans_min,ans_max);
    } else {
        for (int i=log; i>=0; i--) {
            if (p[u][i] != 0 && p[u][i] != p[v][i]) {
                if (ans_min > len_min[u][i]) {
                    ans_min = len_min[u][i];
                }
                if (ans_max < len_max[u][i]) {
                    ans_max = len_max[u][i];
                }
                if (ans_min > len_min[v][i]) {
                    ans_min = len_min[v][i];
                }
                if (ans_max < len_max[v][i]) {
                    ans_max = len_max[v][i];
                }
                u = p[u][i];
                v = p[v][i];
            }
        }
        if (ans_min > len_min[u][0]) {
            ans_min = len_min[u][0];
        }
        if (ans_max < len_max[u][0]) {
            ans_max = len_max[u][0];
        }
        if (ans_min > len_min[v][0]) {
            ans_min = len_min[v][0];
        }
        if (ans_max < len_max[v][0]) {
            ans_max = len_max[v][0];
        }
        return make_pair(ans_min,ans_max);
    }
}
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n-1; i++) {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        a[u].push_back(make_pair(v,w));
        a[v].push_back(make_pair(u,w));
    }
    depth[1] = 0;
    check[1] = true;
    queue<int> q;
    q.push(1);
    parent[1] = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (auto p : a[x]) {
            int y = p.first;
            if (!check[y]) {
                depth[y] = depth[x] + 1;
                check[y] = true;
                parent[y] = x;
                len[y] = p.second;
                q.push(y);
            }
        }
    }
    for (int i=1; i<=n; i++) {
        p[i][0] = parent[i];
        len_min[i][0] = len[i];
        len_max[i][0] = len[i];
    }
    for (int j=1; (1<<j) < n; j++) {
        for (int i=1; i<=n; i++) {
            if (p[i][j-1] != 0) {
                p[i][j] = p[p[i][j-1]][j-1];
                len_min[i][j] = len_min[i][j-1];
                len_max[i][j] = len_max[i][j-1];
                if (p[p[i][j-1]][j-1] != 0) {

                    len_min[i][j] = min(len_min[i][j-1],len_min[p[i][j-1]][j-1]);
                    len_max[i][j] = max(len_max[i][j-1],len_max[p[i][j-1]][j-1]);
                }
                //printf("%d %d %d %d\n",i,j,len_min[i][j],len_max[i][j]);
            }
        }
    }
    int m;
    scanf("%d",&m);
    while (m--) {
        int u, v;
        scanf("%d %d",&u,&v);
        auto p = lca(u,v);
        printf("%d %d\n",p.first,p.second);
    }
    return 0;
}