#include <cstdio>
#include <cmath>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;
void init(vector<int> &tree, vector<int> &a, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
        return;
    }
    init(tree, a, node*2, start, (start+end)/2);
    init(tree, a, node*2+1, (start+end)/2+1, end);
    tree[node] = tree[node*2] * tree[node*2+1];
}
int sign(vector<int> &tree, int node, int start, int end, int left, int right) {
    if (left > end || right < start) {
        return 1;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return sign(tree, node*2, start, (start+end)/2, left, right) * sign(tree, node*2+1, (start+end)/2+1, end, left, right);
}
void update(vector<int> &tree, int node, int start, int end, int i, int value) {
    if (i > end || i < start) {
        return;
    }
    if (start == end) {
        tree[node] = value;
        return;
    }
    update(tree, node*2, start, (start+end)/2, i, value);
    update(tree, node*2+1, (start+end)/2+1, end, i, value);
    tree[node] = tree[node*2] * tree[node*2+1];
}
int main() {
    int n,m;
    while (scanf("%d %d",&n,&m) == 2) {
        vector<int> a(n);
        for (int i=0; i<n; i++) {
            scanf("%d",&a[i]);
            if (a[i] > 0) a[i] = 1;
            if (a[i] < 0) a[i] = -1;
        }
        int h = (int)ceil(log2(n));
        int tree_size = (1 << (h+1));
        vector<int> tree(tree_size);
        init(tree, a, 1, 0, n-1);
        while (m--) {
            char cmd;
            scanf(" %c",&cmd);
            if (cmd == 'C') {
                int index, value;
                scanf("%d %d",&index,&value);
                if (value > 0) value = 1;
                if (value < 0) value = -1;
                update(tree, 1, 0, n-1, index-1, value);
            } else {
                int start, end;
                scanf("%d %d",&start,&end);
                int ans = sign(tree, 1, 0, n-1, start-1, end-1);
                if (ans > 0) {
                    putchar('+');
                } else if (ans < 0) {
                    putchar('-');
                } else {
                    putchar('0');
                }
            }
        }
        puts("");
    }
    return 0;
}