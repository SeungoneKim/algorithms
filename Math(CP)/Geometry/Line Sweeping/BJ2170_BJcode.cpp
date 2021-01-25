#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int,int>> a(2*n);
    for (int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;
        a[i] = make_pair(x,1);
        a[i+n] = make_pair(y,-1);
    }
    sort(a.begin(),a.end());
    int ans = 0;
    int cnt = 0;
    int last = 0;
    for (auto &p : a) {
        if (p.second == 1 && cnt == 0) {
            last = p.first;
        }
        cnt += p.second;
        if (p.second == -1 && cnt == 0) {
            ans += p.first - last;
        }
    }
    cout << ans << '\n';
    return 0;
}