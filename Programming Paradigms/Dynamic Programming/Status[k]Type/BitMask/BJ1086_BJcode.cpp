#include <iostream>
#include <vector>
#include <string>
using namespace std;
long long d[1<<15][100];
long long gcd(long long x, long long y) {
    if (y == 0) return x;
    else return gcd(y, x%y);
}
int main() {
    int n;
    cin >> n;
    vector<string> num(n);
    vector<int> a(n);
    vector<int> len(n);
    for (int i=0; i<n; i++) {
        cin >> num[i];
        len[i] = num[i].size();
    }
    int k;
    cin >> k;
    for (int i=0; i<n; i++) {
        for (int j=0; j<len[i]; j++) {
            a[i] = a[i] * 10 + (num[i][j] - '0');
            a[i] %= k;
        }
    }
    vector<int> ten(51);
    ten[0] = 1;
    for (int i=1; i<=50; i++) {
        ten[i] = ten[i-1] * 10;
        ten[i] %= k;
    }
    d[0][0] = 1;
    for (int i=0; i<(1<<n); i++) {
        for (int j=0; j<k; j++) {
            for (int l=0; l<n; l++) {
                if ((i&(1<<l)) == 0) {
                    int next = j * ten[len[l]];
                    next %= k;
                    next += a[l];
                    next %= k;
                    d[i|(1<<l)][next] += d[i][j];
                }
            }
        }
    }
    long long t1 = d[(1<<n)-1][0];
    long long t2 = 1;
    for (int i=2; i<=n; i++) {
        t2 *= (long long)i;
    }
    long long g = gcd(t1,t2);
    t1 /= g;
    t2 /= g;
    cout << t1 << '/' << t2 << '\n';
    return 0;
}