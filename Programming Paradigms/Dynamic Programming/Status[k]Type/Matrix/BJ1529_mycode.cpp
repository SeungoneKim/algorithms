#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <set>

using namespace std;

typedef vector<vector<long long>> matrix;
const long long mod = 1234567891LL;

matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

bool check(int x) {
    if (x == 0) return true;
    if (x%10 == 4 || x%10 == 7) {
        return check(x/10);
    } else {
        return false;
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,l;
    cin >> n >> l;
    set<int>s;
    matrix ans={{1,0},{0,1}};
    matrix a={{0,0},{0,0}};
    
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(s.count(x)) continue;
        s.insert(x);
        if(check(x)){
            string temp = to_string(x);
            if (temp[0] == '4') {
                if (x%10 == 4) {
                    a[0][0] += 1;
                } else {
                    a[0][1] += 1;
                }
            } else {
                if (x%10 == 4) {
                    a[1][0] += 1;
                } else {
                    a[1][1] += 1;
                }
            }
        }
    }
    while(l>0){
        if(l%2==1){
            ans = ans*a;
        }
        a=a*a;
        l/=2;
    }
    cout << (ans[0][0]+ans[0][1]+ans[1][0]+ans[1][1])%mod << '\n';

    return 0;
}