#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
struct SegmentTree {
    vector<vector<int>> tree;
    int n;
    SegmentTree(int _n) {
        n = _n;
        int h = (int)ceil(log2(n+1));
        int tree_size = (1 << (h+1));
        tree.resize(tree_size);
    }
    void init(vector<int> &a, int node, int start, int end) {
        if (start == end) {
            tree[node].push_back(a[start]);
            return;
        }
        int mid = (start+end)/2;
        init(a, node*2, start, mid);
        init(a, node*2+1, mid+1, end);
        merge(tree[node*2].begin(), tree[node*2].end(), tree[node*2+1].begin(), tree[node*2+1].end(), back_inserter(tree[node]));
    }
    void init(vector<int> &a) {
        init(a, 1, 0, n-1);
    }
    int query(int node, int start, int end, int i, int j, int k) {
        if (i > end || j < start) {
            return 0;
        }
        if (i <= start && end <= j) {
            return tree[node].size() - (upper_bound(tree[node].begin(), tree[node].end(), k) - tree[node].begin());
        }
        int mid = (start+end)/2;
        return query(node*2, start, mid, i, j, k) + query(node*2+1, mid+1, end, i, j, k);
    }
    int query(int i, int j, int k) {
        return query(1, 0, n-1, i, j, k);
    }
};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    SegmentTree tree(n);
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    tree.init(a);
    int m;
    cin >> m;
    int ans = 0;
    while (m--) {
        int t1, t2, t3;
        cin >> t1 >> t2 >> t3;
        int start = ans ^ t1;
        int end = ans ^ t2;
        int k = ans ^ t3;
        ans = tree.query(start-1, end-1, k);
        cout << ans << '\n';
    }
    return 0;
}