#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Edge {
    int start, end, cost;
    bool operator < (const Edge &other) const {
        return cost < other.cost;
    }
};
int p[100001];
int Find(int x) {
    if (x == p[x]) {
        return x;
    } else {
        return p[x] = Find(p[x]);
    }
}
void Union(int x, int y) {
    x = Find(x);
    y = Find(y);
    p[x]=y;
}
int main() {
    int n,m;
    scanf("%d %d",&n,&m);
    for (int i=1; i<=n; i++) {
        p[i] = i;
    }
    vector<Edge> a(m);
    for (int i=0; i<m; i++) {
        scanf("%d %d %d",&a[i].start, &a[i].end, &a[i].cost);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    int cnt = 0;
    for (int i=0; i<m; i++) {
        Edge e = a[i];
        int x = Find(e.start);
        int y = Find(e.end);
        if (x != y) {
            Union(e.start, e.end);
            ans += e.cost;
            cnt += 1;
        }
        if (cnt == n-2) break;
    }
    printf("%d\n",ans);
    return 0;
}