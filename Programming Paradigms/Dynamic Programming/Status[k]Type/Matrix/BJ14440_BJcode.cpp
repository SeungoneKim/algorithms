#include <iostream>
#include <vector>
#include <string>
using namespace std;
using matrix = vector<vector<int>>;
void print(int x) {
    if (x < 10) {
        cout << 0;
    }
    cout << x << '\n';
}
matrix operator * (const matrix &a, const matrix &b) {
    matrix ans = {
        {a[0][0]*b[0][0]+a[0][1]*b[1][0], a[0][0]*b[0][1]+a[0][1]*b[1][1]},
        {a[1][0]*b[0][0]+a[1][1]*b[1][0], a[1][0]*b[0][1]+a[1][1]*b[1][1]}
    };
    for (int i=0; i<2; i++) {
        for (int j=0; j<2; j++) {
            ans[i][j] %= 100;
        }
    }
    return ans;
}
matrix pow(matrix m, int n) {
    if (n == 0) {
        return {{1,0},{0,1}};
    } else if (n == 1) {
        return m;
    } else if (n % 2 == 0) {
        matrix temp = pow(m, n/2);
        return temp*temp;
    } else {
        return m * pow(m, n-1);
    }
}
int main() {
    int x, y, a0, a1, n;
    cin >> x >> y >> a0 >> a1 >> n;
    if (n == 0) {
        print(a0);
    } else if (n == 1) {
        print(a1);
    } else {
        matrix m = {{x,y},{1,0}};
        m = pow(m, n-1);
        int ans = m[0][0]*a1 + m[0][1]*a0;
        print(ans%100);
    }
    return 0;
}