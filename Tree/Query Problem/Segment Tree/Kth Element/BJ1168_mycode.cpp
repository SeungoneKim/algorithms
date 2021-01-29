#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int MAX=65536;

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
int sum(vector<int> &tree, int node, int start, int end, int i, int j) {
    if (i > end || j < start) {
        return 0;
    }
    if (i <= start && end <= j) {
        return tree[node];
    }
    return sum(tree, node*2, start, (start+end)/2, i, j) + sum(tree, node*2+1, (start+end)/2+1, end, i, j);
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

    int n,k;
    cin >> n >> k;

    int h = (int)ceil(log2(n));
    int tree_size = (1 << (h+1));

    vector<int> ans(n+1);
    vector<int> tree(tree_size);
    init(tree,1,1,n);
    int last=0;

    cout << "<";
    for(int i=n;i>=1;i--){
        int pre=0;
        if(last!=0){
            pre=sum(tree,1,1,n,1,last);
        }
        int idx=(pre+k)%i;
        if(idx==0){
            idx=i;
        }
        last= kth(tree,1,1,n,idx);
        cout << last;
        if(i!=1){
            cout << ", ";
        }
        update(tree,1,1,n,last,-1);
    }

    cout << ">";

    return 0;
}