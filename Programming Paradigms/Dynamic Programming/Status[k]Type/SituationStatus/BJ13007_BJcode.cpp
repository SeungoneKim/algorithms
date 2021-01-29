#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <climits>

using namespace std;

int mod=1000000007LL;
long long fact[1000001];
long long inv[1000001];
long long fact_inv[1000001];

long long comb(int n, int k) {
    if (k < 0 || k > n) return 0;
    long long ans = fact[n];
    ans = (ans * fact_inv[k]) % mod;
    ans = (ans * fact_inv[n-k]) % mod;
    return ans;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,a,b,c;
    cin >> n >> a >> b >> c;

    fact[0] = 1;
    for (int i=1; i<=n; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    inv[1] = 1;
    for (int i=2; i<=n; i++) {
        inv[i] = (inv[mod%i] * (mod - mod/i)) % mod;
    }
    fact_inv[0] = 1;
    for (int i=1; i<=n; i++) {
        fact_inv[i] = (fact_inv[i-1] * inv[i]) % mod;
    }
    
    long long ans = 0;
    long long sign = 1;
    for (int i=0; i<=n; i++) {
        long long temp = (comb(n,i) * comb(n-i,a)) % mod;
        temp = (temp * comb(n-i,b)) % mod;
        temp = (temp * comb(n-i,c)) % mod;
        ans += sign*temp;
        ans %= mod;
        ans = (ans + mod) % mod;
        sign = -sign;
    }
    cout << ans << '\n';



    return 0;
}