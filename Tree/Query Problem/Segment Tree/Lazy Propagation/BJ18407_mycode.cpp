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

// Global variables
int n;
int MAX=1000000000;

// Global arrays
vector<pair<int,int>>info;
vector<long long>tree;
vector<long long>lazy;

// functions

long long init(vector<long long> &a, vector<long long> &tree, int node, int start, int end) {
    if (start == end) {
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, node*2, start, (start+end)/2) + init(a, tree, node*2+1, (start+end)/2+1, end);
    }
}
void update_lazy(vector<long long> &tree, vector<long long> &lazy, int node, int start, int end) {
    if (lazy[node] != 0) {
        tree[node] += (end-start+1)*lazy[node];
        // leaf가 아니면
        if (start != end) {
            lazy[node*2] += lazy[node];
            lazy[node*2+1] += lazy[node];
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
        tree[node] += (end-start+1)*diff;
        if (start != end) {
            lazy[node*2] += diff;
            lazy[node*2+1] += diff;
        }
        return;
    }
    update_range(tree, lazy, node*2, start, (start+end)/2, left, right, diff);
    update_range(tree, lazy, node*2+1, (start+end)/2+1, end, left, right, diff);
    tree[node] = tree[node*2] + tree[node*2+1];
}
long long query(vector<long long>&tree, int node, int start, int end, int i, int j){
    if(i>end || j<start) return -1;
    if(i<=start && end<=j) return tree[node];
    int m1=query(tree,2*node,start,(start+end)/2,i,j);
    int m2=query(tree,2*node+1,(start+end)/2+1,end,i,j);
    if(m1==-1){
        return m2;
    }
    else if(m2==-1){
        return m1;
    }
    else{
        return max(m1,m2);
    }
}

void input(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);    
    
    cin >> n;
    info.resize(n+1);
    for(int i=1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        info[i].first=a;
        info[i].second=b;
    }
}

long long solve(){

    long long answ=0;

    int h= ceil(log2(MAX));
    int treesize=(1<<(h+1));
    tree.resize(treesize);

    for(int i=1;i<=n;i++){
        int howmuch= query(tree,1,0,10000,info[i].second,info[i].first+info[i].second);
        update_range(tree,lazy,1,0,10000,info[i].second,info[i].first+info[i].second,howmuch+1);
    }

    answ= query(tree,1,0,10000,0,10000);

    return answ;
}

// main function
int main(){

    input();
    cout << solve();
    cout << '\n';

    return 0;
}