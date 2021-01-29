#include <cstdio>
#include <cstring>
int a[16][16];
char str[20];
int d[1<<16];
int main() {
    int n;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            scanf("%d",&a[i][j]);
        }
    }
    scanf("%s",str);
    int start = 0;
    memset(d,-1,sizeof(d));
    for (int i=n-1; i>=0; i--) {
        start = start * 2;
        if (str[i] == 'Y') {
            start += 1;
        }
    }
    int p;
    scanf("%d",&p);
    d[start] = 0;
    for (int i=0; i<(1<<n); i++) {
        if (d[i] == -1) continue;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) { // j가 켜져 있음
                for (int k=0; k<n; k++) {
                    if ((i&(1<<k))==0) { // k가 꺼져있음
                        if (d[i|(1<<k)] == -1 || d[i|(1<<k)] > d[i] + a[j][k]) {
                            d[i|(1<<k)] = d[i]+a[j][k];
                        }
                    }
                }
            }
        }
    }
    int ans = -1;
    for (int i=0; i<(1<<n); i++) {
        if (d[i] == -1) continue;
        int cnt = 0;
        for (int j=0; j<n; j++) {
            if (i&(1<<j)) {
                cnt += 1;
            }
        }
        if (cnt >= p) {
            if (ans == -1 || ans > d[i]) {
                ans = d[i];
            }
        }
    }
    printf("%d\n",ans);

    return 0;
}