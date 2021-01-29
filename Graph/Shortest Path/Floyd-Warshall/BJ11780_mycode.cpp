#include <cstdio>
#include <queue>
using namespace std;
#define next _next
int a[1001][1001];
int next[1001][1001];
int distance[1001];
bool check[1001];
const int inf = 1000000000;
void path(int x, int y) {
    if (next[x][y] == -1) {
        printf("0\n");
        return;
    }
    queue<int> q;
    q.push(x);
    while (x != y) {
        x = next[x][y];
        q.push(x);
    }
    printf("%d ",q.size());
    while (!q.empty()) {
        printf("%d ",q.front());
        q.pop();
    }
    printf("\n");
}
int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) {
                a[i][j] = 0;
            } else {
                a[i][j] = inf;
            }
            next[i][j] = -1;
        }
    }
    for (int i=0; i<m; i++) {
        int from, to, cost;
        scanf("%d %d %d", &from, &to, &cost);
        if (a[from][to] > cost) {
            a[from][to] = cost;
            next[from][to] = to;
        }
    }
    for (int k=1; k<=n; k++) {
        for (int i=1; i<=n; i++) {
            for (int j=1; j<=n; j++) {
                if (a[i][j] > a[i][k] + a[k][j]) {
                    a[i][j] = a[i][k] + a[k][j];
                    next[i][j] = next[i][k];
                }
            }
        }
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (a[i][j] == inf) {
                printf("%d ", 0);
            } else {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            if (i == j) {
                printf("0\n");
            } else if (a[i][j] == inf) {
                printf("0\n");
            } else {
                path(i, j);
            }
        }
    }
    return 0;
}