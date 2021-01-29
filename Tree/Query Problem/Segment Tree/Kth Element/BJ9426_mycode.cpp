#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX=65536;

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

int main(){

    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    int h = (int)ceil(log2(MAX+1));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<k-1;i++){
        update(tree,1,0,MAX-1,a[i],1);
    }
    long long answ=0;
    int cnt=(k+1)/2;
    for(int i=k-1;i<n;i++){
        update(tree,1,0,MAX-1,a[i],1);
        answ+= (long long)kth(tree,1,0,MAX-1,cnt);
        update(tree,1,0,MAX-1,a[i-k+1],-1);
    }

    cout << answ << '\n';

    return 0;
}