#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
using Result = vector<pair<int,int>>;
struct Building {
    int left, right, height;
};
void append(Result &ans, pair<int,int> p) {
    int n = ans.size();
    if (n > 0) {
        if (ans[n-1].second == p.second) {
            return;
        }
        if (ans[n-1].first == p.first) {
            ans[n-1].second = p.second;
            return;
        }
    }
    ans.push_back(p);
}
Result merge(Result &l, Result &r) {
    Result ans;
    int h1 = 0;
    int h2 = 0;
    int i = 0;
    int j = 0;
    while (i < l.size() && j < r.size()) {
        auto &u = l[i];
        auto &v = r[j];
        if (u.first < v.first) { 
            int x = u.first;
            h1 = u.second;
            int h = max(h1, h2);
            append(ans, make_pair(x, h));
            i += 1;
        } else {
            int x = v.first;
            h2 = v.second;
            int h = max(h1, h2);
            append(ans, make_pair(x, h));
            j += 1;
        }
    }
    while (i < l.size()) {
        append(ans, l[i]);
        i += 1;
    }
    while (j < r.size()) {
        append(ans, r[j]);
        j += 1;
    }
    return ans;
}
Result go(vector<Building> &a, int start, int end) {
    if (start == end) {
        Result ans = {
            {a[start].left, a[start].height},
            {a[start].right, 0}
        };
        return ans;
    }
    int mid = (start + end) / 2;
    auto l = go(a, start, mid);
    auto r = go(a, mid+1, end);
    return merge(l, r);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<Building> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i].left >> a[i].height >> a[i].right;
    }
    sort(a.begin(), a.end(), [](auto &u, auto &v) {
        return make_tuple(u.left, u.height, u.right) < make_tuple(v.left, v.height, v.right);
    });
    auto ans = go(a, 0, n-1);
    for (auto &p : ans) {
        cout << p.first << ' ' << p.second << ' ';
    }
    cout << '\n';
    return 0;
}