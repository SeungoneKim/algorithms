#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <climits>
#include <bitset>

using namespace std;

long long sum(vector<long long> &tree, int x) {
    long long ans = 0;
    for (int i=x; i>0; i -= i&-i) {
        ans += tree[i];
    }
    return ans;
}
void update(vector<long long> &tree, int x, long long diff) {
    for (int i=x; i<tree.size(); i += i&-i) {
        tree[i] += diff;
    }
}
void update(vector<long long> &tree1, vector<long long> &tree2, int x, int y, long long diff) {
    update(tree1, x, diff);
    update(tree1, y+1, -diff);
    update(tree2, x, diff*(x-1));
    update(tree2, y+1, -diff*y);
}
long long range_sum(vector<long long> &tree1, vector<long long> &tree2, int x) {
    return sum(tree1, x) * x - sum(tree2, x);
}
long long range_sum(vector<long long> &tree1, vector<long long> &tree2, int x, int y) {
    return range_sum(tree1, tree2, y) - range_sum(tree1, tree2, x-1);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<long long> a(n+1);
    vector<long long> tree1(n+2);
    vector<long long> tree2(n+2);
    for (int i=1; i<=n; i++) {
        cin >> a[i];
        update(tree1, tree2, i, i, a[i]);
    }
    m += k;
    while (m--) {
        int what;
        cin >> what;
        if (what == 1) {
            int start, end;
            long long val;
            cin >> start >> end >> val;
            update(tree1, tree2, start, end, val);
        } else {
            int start, end;
            cin >> start >> end;
            cout << range_sum(tree1, tree2, start, end) << '\n';
        }
    }

    return 0;
}