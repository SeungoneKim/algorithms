#include <iostream>
#include <vector>
using namespace std;
int main() {
    int n;
    long long m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    long long ans=0;
    for (int i=1; i<(1<<n); i++) {
        int cnt=0;
        long long p=1;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                p *= a[j];
                cnt += 1;
                if (p > m) {
                    cnt = -1;
                    break;
                }
            }
        }
        if (cnt == -1) continue;
        if (cnt % 2 == 0) {
            ans -= (m/p);
        } else {
            ans += (m/p);
        }
    }
    cout << ans << '\n';
    return 0;
}

