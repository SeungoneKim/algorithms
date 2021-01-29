#include <iostream>
#include <tuple>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<int> tsort(vector<vector<int>> &g) {
    int n = g.size();
    vector<int> ind(n);
    for (int i=0; i<n; i++) {
        for (int j : g[i]) {
            ind[j] += 1;
        }
    }
    vector<int> order;
    queue<int> q;
    for (int i=0; i<n; i++) {
        if (ind[i] == 0) {
            q.push(i);
            order.push_back(i);
        }
    }
    while (!q.empty()) {
        int x = q.front(); q.pop();
        for (int y : g[x]) {
            ind[y] -= 1;
            if (ind[y] == 0) {
                q.push(y);
                order.push_back(y);
            }
        }
    }
    return order;
}
bool go(int k, vector<int> &b, vector<int> &order, vector<vector<int>> &g) {
    int n = b.size();
    vector<int> a(n);
    for (int x : order) {
        a[x] = 2000000000;
        for (int y : g[x]) { // a[x] < a[y]
            a[x] = min(a[x], a[y]-1);
        }
        if (x < k) {
            if (b[x] > a[x]) return false;
            a[x] = b[x];
        }
        if (a[x] <= 0) {
            return false;
        }
    }
    for (int i=0; i<n; i++) {
        if (a[i] > b[i]) return true;
        if (a[i] < b[i]) return false;
    }
    return true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<vector<int>> gr(n);
    vector<int> b(n);
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    while (m--) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        g[u].push_back(v);
        gr[v].push_back(u);
    }
    vector<int> order;
    order = tsort(g);
    if (order.size() != n) {
        cout << -1 << '\n';
        return 0;
    }
    int ans = 0;
    int left = 0;
    int right = n-1;
    reverse(order.begin(), order.end());
    while (left <= right) {
        int mid = (left + right) / 2;
        if (go(mid, b, order, g)) {
            left = mid+1;
            ans = max(ans, mid);
        } else {
            right = mid-1;
        }
    }
    reverse(order.begin(), order.end());
    vector<int> a(n);
    for (int x : order) {
        a[x] = 1;
        for (int y : gr[x]) { // a[x] > a[y]
            a[x] = max(a[x], a[y]+1);
        }
        if (x < ans) {
            a[x] = b[x];
        } else if (x == ans) {
            a[x] = max(b[x]+1, a[x]);
        }
    }
    for (int i=0; i<n; i++) {
        cout << a[i] << ' ';
    }
    cout << '\n';
    return 0;
}