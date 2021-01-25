#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(n));
    vector<pair<int,int>> people;
    vector<pair<int,int>> store;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] == 1) {
                people.emplace_back(i, j);
            } else if (a[i][j] == 2) {
                store.emplace_back(i, j);
            }
        }
    }
    vector<int> d(store.size());
    for (int i=0; i<m; i++) {
        d[i] = 1;
    }
    sort(d.begin(),d.end());
    int ans = -1;
    do {
        int sum = 0;
        for (auto &p : people) {
            vector<int> dists;
            for (int i=0; i<store.size(); i++) {
                if (d[i] == 0) continue;
                auto &s = store[i];
                int d1 = p.first-s.first;
                int d2 = p.second-s.second;
                if (d1 < 0) d1 = -d1;
                if (d2 < 0) d2 = -d2;
                int dist = d1+d2;
                dists.push_back(dist);
            }
            sum += *min_element(dists.begin(),dists.end());
        }
        if (ans == -1 || ans > sum) {
            ans = sum;
        }
    } while (next_permutation(d.begin(),d.end()));
    cout << ans << '\n';
    return 0;
}