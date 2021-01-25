#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long> x(n);
    vector<long long> y(n);
    for (int i=0; i<n; i++) {
        cin >> x[i] >> y[i];
    }
    x.push_back(x[0]); y.push_back(y[0]);
    long long ans = 0;
    for (int i=0; i<n; i++) {
        ans += x[i] * y[i+1];
        ans -= y[i] * x[i+1];
    }
    if (ans < 0) ans = -ans;
    cout << ans/2 << '.';
    if (ans%2 == 0) {
        cout << '0';
    } else {
        cout << '5';
    }
    cout << '\n';
    return 0;
}