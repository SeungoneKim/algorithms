#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int BLANK = ' ';
const int STAR = '*';
void go(vector<vector<char>> &a, int x, int y, int n, char color) {
    if (color == BLANK) {
        int m = 2*n-1;
        for (int i=x; i<x+n; i++) {
            for (int j=0; j<m; j++) {
                a[i][j+i-x+y] = BLANK;
            }
            m -= 2;
        }
    } else if (color == STAR) {
        if (n != 1) {
            int m = n/2;
            go(a,x,y,m,STAR);
            go(a,x+m,y-m,m,STAR);
            go(a,x+m,y+m,m,STAR);
            if (n == 3) {
                go(a,x+1,y,1,BLANK);
            } else {
                go(a,x+m,y-m+1,m,BLANK);
            }
        }
    }
}
int main() {
    int n;
    cin >> n;
    vector<vector<char>> a(n, vector<char>(2*n, STAR));
    go(a,0,n-1,n,STAR);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n-i-1; j++) {
            a[i][j] = BLANK;
            a[i][2*n-j-2] = BLANK;
        }
        a[i][2*n-1] = BLANK;
    }
    for (int i=0; i<n; i++) {
        cout << string(a[i].begin(), a[i].end()) << '\n';
    }
    return 0;
}