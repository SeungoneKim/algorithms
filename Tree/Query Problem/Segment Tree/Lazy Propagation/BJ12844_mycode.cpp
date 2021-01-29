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
#include <bitset>

using namespace std;

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2)^init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}
void update_lazy(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        if((end-start+1)%2==1){
            tree[node] ^= lazy[node];
        }
        // leaf가 아니면
        if (start != end) {
            lazy[node*2] ^= lazy[node];
            lazy[node*2+1] ^= lazy[node];
        }
        lazy[node] = 0;
    }
}
void update_range(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right, long long diff) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return;
    }
    if (left <= start && end <= right) {
        if((end-start+1)%2==1){
            tree[node] ^= diff;
        }
        if (start != end) {
            lazy[node*2] ^= diff;
            lazy[node*2+1] ^= diff;
        }
        return;
    }
    update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] ^ tree[node*2+1];
}
long long queryfunc(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end, int left, int right) {
    update_lazy(tree, lazy, node, start, end);
    if (left > end || right < start) {
        return 0;
    }
    if (left <= start && end <= right) {
        return tree[node];
    }
    return queryfunc(tree, lazy, node*2, start, (start+end)/2, left, right) ^ queryfunc(tree, lazy, node*2+1, (start+end)/2+1, end, left, right);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long>a(n+1);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int h=ceil(log2(n));
    int treesize= (1<<(h+1));

    vector<long long>tree(treesize);
    vector<long long>lazy(treesize);
    init(a,tree,1,0,n-1);

    int query;
    cin >> query;
    while(query--){
        int which;
        cin >> which;
        if(which==1){
            int from,to,howmuch;
            cin >> from >> to >> howmuch;
            update_range(tree,lazy,1,0,n-1,from,to,howmuch);
        }
        else{
            int from,to;
            cin >> from >> to;
            cout << queryfunc(tree,lazy,1,0,n-1,from,to) << '\n';
        }
    }


    return 0;
}