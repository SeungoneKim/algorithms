#include <iostream>
using namespace std;
int a[16];
bool d[81][81][81][81];
int main() {
    int n;
    cin >> n;
    int sum = 0;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int s2 = sum/2;
    int lim1 = s2/2;
    int lim2 = s2-1;
    d[0][0][0][0] = true;
    for (int i=0; i<n; i++) {
        for (int l1=lim1; l1>=0; l1--) {
            for (int l2=lim1; l2>=0; l2--) {
                for (int l3=lim2; l3>=0; l3--) {
                    for (int l4=lim2; l4>=0; l4--) {
                        if (d[l1][l2][l3][l4] == false) {
                            continue;
                        }
                        if (l1+a[i] <= lim1) {
                            d[l1+a[i]][l2][l3][l4] = true;
                        }
                        if (l2+a[i] <= lim1) {
                            d[l1][l2+a[i]][l3][l4] = true;
                        }
                        if (l3+a[i] <= lim2) {
                            d[l1][l2][l3+a[i]][l4] = true;
                        }
                        if (l4+a[i] <= lim2) {
                            d[l1][l2][l3][l4+a[i]] = true;
                        }
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int i=1; i<=lim1; i++) {
        for (int j=1; j<=lim2; j++) {
            if (d[i][i][j][j]) {
                if (i*j > ans) {
                    ans = i*j;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}