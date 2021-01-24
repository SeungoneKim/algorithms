#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int l;
void update(vector<int> &tree, int i, int diff) {
    while (i <= l) {
        tree[i] += diff;
        i += (i & -i);
    }
}
int sum(vector<int> &tree, int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}
int sum(vector<int> &tree, int l, int r) {
    if (l > r) return 0;
    return sum(tree, r) - sum(tree, l-1);
}
int main() {
    int n;
    scanf("%d",&n);
    vector<int> a(n);
    vector<int> b(n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    map<int, int> d;
    for (int i=0; i<b.size(); i++) {
        d[b[i]] = i+1;
    }
    for (int i=0; i<n; i++) {
        a[i] = d[a[i]];
    }
    long long ans = 0;
    vector<int> tree(n+1);
    l = n;
    for (int i=0; i<n; i++) {
        ans += (long long)sum(tree, a[i]+1, n);
        update(tree, a[i], 1);
    }
    printf("%lld\n",ans);
    return 0;
}