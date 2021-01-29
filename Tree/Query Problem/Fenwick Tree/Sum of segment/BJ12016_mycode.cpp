#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int sum(vector<int> &tree, int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= i&-i;
    }
    return ans;
}
int sum(vector<int> &tree, int start, int end) {
    return sum(tree, end) - sum(tree, start-1);
}
void update(vector<int> &tree, int i, int diff) {
    while (i < tree.size()) {
        tree[i] += diff;
        i += i&-i;
    }
}
int main() {
    int n;
    scanf("%d",&n);
    vector<pair<int,int>> a(n+1);
    vector<int> tree(n+1);
    for (int i=1; i<=n; i++) {
        scanf("%d",&a[i].first);
        a[i].second = i;
        update(tree, i, 1);
    }
    sort(a.begin()+1, a.end());
    long long total = 0;
    int last = 0;
    vector<long long> ans(n+1);
    int remain = n;
    for (int i=1; i<=n; i++) {
        total += (long long)(a[i].first - last)*remain;
        remain -= 1;
        last = a[i].first;
        ans[a[i].second] = total - (long long)sum(tree, a[i].second+1, n);
        update(tree, a[i].second, -1);
    }
    for (int i=1; i<=n; i++) {
        printf("%lld\n",ans[i]);
    }
    return 0;
}