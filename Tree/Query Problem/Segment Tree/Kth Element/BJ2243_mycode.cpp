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
const int MAX = 1000000;
long long init(vector<int>& a, vector<int>& tree, int node, int start, int end) {
    if (start == end) {
        tree[node] = a[start];
    } else {
        tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
    return tree[node];
}
void update(vector<int>& tree, int node, int start, int end, int i, long long diff) {
    if (i < start || i > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(tree, node*2, start, (start+end)/2, i, diff);
        update(tree, node*2+1, (start+end)/2+1, end, i, diff);
    }
}
int kth(vector<int> &tree, int node, int start, int end, int k) {
    if (start == end) {
        return start;
    } else {
        if (k <= tree[node*2]) {
            return kth(tree, node*2, start, (start+end)/2, k);
        } else {
            return kth(tree, node*2+1, (start+end)/2+1, end, k-tree[node*2]);
        }
    }
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> a(MAX+1);
    int h = (int)ceil(log2(MAX+1));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);

    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x==1){
            int y;
            cin >> y;
            int box = kth(tree,1,1,MAX,y);
            cout << box << '\n';
            a[box]--;
            update(tree,1,1,MAX,box,-1);
        }
        else{
            int y,z;
            cin >> y >> z;
            a[y]+=z;
            update(tree,1,1,MAX,y,z);
        }
    }

    return 0;
}