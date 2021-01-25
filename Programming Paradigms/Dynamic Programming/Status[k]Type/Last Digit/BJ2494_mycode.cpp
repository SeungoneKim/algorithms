#include <cstdio>
#include <cstring>
int a[10000];
int b[10000];
int d[10000][10];
int how[10000][10];
int to[10000][10];
int cost[10000][10];
int n;
int go(int index, int turn) {
    if (index == n) {
        return 0;
    }
    int &ans = d[index][turn];
    if (ans != -1) {
        return ans;
    }
    int cur = (a[index] + turn) % 10;
    // left
    int cost_l = (b[index] + 10 - cur) % 10;
    int left = go(index+1, (turn + cost_l) % 10) + cost_l;
    int cost_r = (cur + 10 - b[index]) % 10;
    int right = go(index+1, turn) + cost_r;
    if (left < right) {
        ans = left;
        how[index][turn] = 1;
        to[index][turn] = (turn+cost_l) % 10;
        cost[index][turn] = cost_l;
    } else {
        ans = right;
        how[index][turn] = 2;
        to[index][turn] = turn;
        cost[index][turn] = cost_r;
    }
    return ans;
}
void print(int index, int turn) {
    if (index == n) {
        return;
    }
    if (cost[index][turn] == 0) {
        print(index+1, turn);
    } else {
        printf("%d ",index+1);
        if (how[index][turn] == 2) {
            printf("-");
        }
        printf("%d\n",cost[index][turn]);
        print(index+1, to[index][turn]);
    }
}
int main() {
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%1d",&a[i]);
    }
    for (int i=0; i<n; i++) {
        scanf("%1d",&b[i]);
    }
    memset(d,-1,sizeof(d));
    printf("%d\n",go(0, 0));
    print(0, 0);
    return 0;
}