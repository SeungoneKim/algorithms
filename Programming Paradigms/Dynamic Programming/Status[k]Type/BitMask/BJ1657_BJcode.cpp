#include <iostream>
#include <cassert>
#include <vector>
using namespace std;
const int MAX = 100000;
vector<int> primes;
int calc(int index, long long num, long long m) {
    if (index >= primes.size()) return 0;
    int ans = 0;
    if (num*primes[index] > m) return 0;
    ans += m/(num*primes[index]);
    ans += calc(index+1, num, m);
    ans -= calc(index+1, num*primes[index], m);
    return ans;
}
bool c[MAX+1];
int main() {
    for (int i=2; i<=MAX; i++) {
        if (c[i]) continue;
        primes.push_back(i*i);
        for (int j=i+i; j<=MAX; j+=i) {
            c[j] = true;
        }
    }
    int n;
    cin >> n;
    long long left = 0;
    long long right = 2147483647;
    long long ans = right;
    while (left <= right) {
        long long mid = (left + right) / 2;
        int cnt = mid - calc(0, 1, mid);
        if (cnt >= n) {
            ans = mid;
            right = mid-1;
        } else {
            left = mid+1;
        }
    }
    cout << ans << '\n';
    return 0;
}

