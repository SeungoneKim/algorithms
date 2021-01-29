#include <iostream>
using namespace std;
int a[1001][1001];
int main() {
    int n,m;
    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            cin >> a[i][j];
        }
    }
    int ans = 0;
    for (int i=0; i<n; i++) {
        int val = a[i][m-1];
        for (int j=m-2; j>=0; j--) {
            if (a[i][j] > val) {
                val = a[i][j];
            } else {
                val = a[i][j]-1;
            }
        }
        ans ^= val;
    }
    if (ans > 0) {
        cout << "koosaga" << '\n';
    } else {
        cout << "cubelover" << '\n';
    }
    return 0;
}