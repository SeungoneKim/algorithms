#include <cstdio>
int n;
int a[100];
int b[100];
int turn[10] = {0,1,1,1,2,2,2,1,1,1};
int d[100][10][10]; 
int go(int i, int j, int k) {
    if (i == n) {
        return 0;
    }
    if (d[i][j][k] != -1) {
        return d[i][j][k];
    }
    int original = (a[i] + j) % 10;
    int to = b[i];
    for (int three = 0; three < 10; three++) {
        for (int two = 0; two < 10; two++) {
            int from = (original + two + three) % 10;
            int one = to - from;
            if (one < 0) one += 10;
            int cost = turn[one] + turn[two] + turn[three];
            cost += go(i+1, (k+two+three) % 10, three);
            if (d[i][j][k] == -1 || d[i][j][k] > cost) {
                d[i][j][k] = cost;
            }
        }
    }
    return d[i][j][k];
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%1d",&a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%1d",&b[i]);
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<10; j++) {
            for (int k=0; k<10; k++) {
                d[i][j][k] = -1;
            }
        }
    }
    printf("%d\n",go(0,0,0));
}