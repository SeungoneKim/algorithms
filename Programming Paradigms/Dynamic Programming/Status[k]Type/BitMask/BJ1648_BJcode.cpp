#include <iostream>
using namespace std;
long long f[101];
long long g[101];
long long h[101];
int main() {
    f[0] = 1;
    f[1] = 1;
    g[0] = 0;
    g[1] = 1;
    h[0] = 0;
    h[1] = 1;
    for (int i=2; i<=100; i++) {
        f[i] = f[i-1] + f[i-2] + g[i-1] + 2*h[i-1];
        g[i] = f[i-1] + g[i-2];
        h[i] = f[i-1] + h[i-1];
        if (f[i] >= 2147483647LL) break;
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cout << f[n] << '\n';
    }
    return 0;
}