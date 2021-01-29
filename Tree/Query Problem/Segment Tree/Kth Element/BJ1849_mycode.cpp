#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <climits>

using namespace std;

void init(vector<int> &tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = 1;
        return;
    }
    init(tree, node*2, start, (start+end)/2);
    init(tree, node*2+1, (start+end)/2+1, end);
    tree[node] = tree[node*2] + tree[node*2+1];
}
void update(vector<int> &tree, int node, int start, int end, int i, int diff) {
    if (i > end || i < start) {
        return;
    }
    if (start == end) {
        tree[node] += diff;
        return;
    }
    update(tree, node*2, start, (start+end)/2, i, diff);
    update(tree, node*2+1, (start+end)/2+1, end, i, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
int kth(vector<int> &tree, int node, int start, int end, int k) {
    if (start == end) {
        return start;
    }
    if (k <= tree[node*2]) {
        return kth(tree, node*2, start, (start+end)/2, k);
    } else {
        return kth(tree, node*2+1, (start+end)/2+1, end, k-tree[node*2]);
    }
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    int h = (int)ceil(log2(n+1));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);

    vector<int>answ(n+1);
    init(tree,1,1,n);
    for(int i=1;i<=n;i++){
        int k=a[i]+1;
        int w=kth(tree,1,1,n,k);
        answ[w]=i;
        update(tree,1,1,n,w,-1);
    }    
    for(int i=1;i<=n;i++){
        cout << answ[i] << '\n';
    }




    return 0;
}