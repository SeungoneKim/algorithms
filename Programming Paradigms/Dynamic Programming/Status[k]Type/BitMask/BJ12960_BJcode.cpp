#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
const int inf = 100000000;
string a[47];
int n, m;
int d[4*47][1<<4];
int go(int index, int state) {
    if (index == n*m) {
        if (state == 0) return 0;
        else return -inf;
    }
    if (index > n*m) return -inf;
    int &ans = d[index][state];
    if (ans != -1) return ans;
    int i = index/m;
    int j = index%m;
    if (a[i][j] == 'X') {
        return ans = go(index+1, state>>1);
    }
    ans = go(index+1, state>>1);
    if ((state&1) == 0) {
        if ((i+j)%2==0) { // Black
            // BW
            // W.
            if (j+1 < m && i+1 < n) {
                if ((state&2) == 0 && a[i][j+1] == '.' && a[i+1][j] == '.') {
                    ans = max(ans, go(index+2, (state>>2) | (1<<(m-2))) + 1);
                }
            }
        } else { // White
            // WB
            // .W
            if (j+1 < m && i+1 < n) {
                if ((state&2) == 0 && a[i][j+1] == '.' && a[i+1][j+1] == '.') {
                    ans = max(ans, go(index+2, (state>>2) | (1<<(m-1))) + 1);
                }
            }
            // .W
            // WB
            if (j-1 >= 0 && i+1 < n) {
                if ((state&(1<<(m-1))) == 0 && a[i+1][j-1] == '.' && a[i+1][j] == '.') {
                    ans = max(ans, go(index+1, (state>>1) | (1<<(m-1)) | (1<<(m-2))) + 1);
                }
            }
            // W.
            // BW
            if (i+1 < n && j+1 < m) {
                if (a[i+1][j] == '.' && a[i+1][j+1] == '.') {
                    ans = max(ans, go(index+2, (state>>2) | (1<<(m-1)) | (1<<(m-2))) + 1);
                }
            }
        }
    }
    return ans;
}
int main() {
    cin >> n >> m;
    vector<string> b(n);
    for (int i=0; i<n; i++) {
        cin >> b[i];
    }
    for (int j=0; j<m; j++) {
        for (int i=0; i<n; i++) {
            a[j] += b[i][j];
        }
    }
    swap(n,m);
    memset(d,-1,sizeof(d));
    cout << go(0, 0) << '\n';
    return 0;
}