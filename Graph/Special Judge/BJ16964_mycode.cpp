#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a[100000];
bool check[100000];
vector<int> dfs_order;
void dfs(int x) {
    if (check[x]) return;
    dfs_order.push_back(x);
    check[x] = true;
    for (int y : a[x]) {
        dfs(y);
    }
}
int main() {
    int n;
    cin >> n;
    for (int i=0; i<n-1; i++) {
        int u, v;
        cin >> u >> v;
        u -= 1; v -= 1;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    vector<int> b(n);
    vector<int> order(n);
    for (int i=0; i<n; i++) {
        cin >> b[i];
        b[i] -= 1;
        order[b[i]] = i;
    }
    for (int i=0; i<n; i++) {
        sort(a[i].begin(), a[i].end(), [&](const int &u, const int &v) {
            return order[u] < order[v];
        });
    }
    dfs(0);
    if (dfs_order == b) {
        cout << 1 << '\n';
    } else {
        cout << 0 << '\n';
    }
    return 0;
}