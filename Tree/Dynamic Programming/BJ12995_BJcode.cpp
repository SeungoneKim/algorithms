#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const long long mod = 1000000007;
vector<int> g[51]; // 입력 그래프
vector<int> a[51]; // 트리
long long d[51][51][51];
void dfs(int x, int parent) {
    for (int y : g[x]) {
        if (y == parent) continue;
        a[x].push_back(y);
        dfs(y, x);
    }
}
long long go(int x, int k, int e) {
    long long &ans = d[x][k][e];
    if (ans != -1) return ans;
    if (k == 0) {
        return 1;
    }
    if (e == a[x].size()) {
        if (k == 1) {
            return 1;
        } else {
            return 0;
        }
    }
    ans = 0;
    for (int i=0; i<k; i++) {
        long long t1 = go(a[x][e], i, 0);
        long long t2 = go(x, k-i, e+1);
        ans += t1*t2;
        ans %= mod;
    }
    return ans;
}
int main() {
    int n, k;
    cin >> n >> k;
    for (int i=0; i<n-1; i++) {
        int u,v;
        cin >> u >> v;
        u -= 1;
        v -= 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    memset(d,-1,sizeof(d));
    long long ans = 0;
    for (int i=0; i<n; i++) {
        ans += go(i, k, 0);
    }
    ans %= mod;
    cout << ans << '\n';
    return 0;
}