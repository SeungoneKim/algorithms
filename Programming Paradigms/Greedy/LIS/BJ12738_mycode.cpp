#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <cassert>
#include <map>

using namespace std;

const int MAX=1000000;

void update(vector<int>& tree, int node, int start, int end, int i, int value) {
    if (i < start || i > end) return;
    tree[node] = max(tree[node],value);
    if (start != end) {
        update(tree, node*2, start, (start+end)/2, i, value);
        update(tree, node*2+1, (start+end)/2+1, end, i, value);
    }
}

int query(vector<int>&tree, int node, int start, int end, int i, int j){
    if(i>end || j<start) return 0;
    if(i<=start && end<=j) return tree[node];
    int m1=query(tree,2*node,start,(start+end)/2,i,j);
    int m2=query(tree,2*node+1,(start+end)/2+1,end,i,j);
    return max(m1,m2);
}

int main(){

    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>b(n);

    for(int i=0;i<n;i++){
        cin >> a[i];
        b[i]=a[i];
    }

    sort(b.begin(),b.end());
    b.erase(unique(b.begin(),b.end()),b.end());
    map<int,int>d;
    for(int i=0;i<b.size();i++){
        d[b[i]]=i+1;
    }
    for(int i=0;i<n;i++){
        a[i] = d[a[i]];
    }

    int h = (int)ceil(log2(MAX));
    int tree_size = (1<<(h+1));
    vector<int>tree(tree_size);
    int answ=0;
    for(int i=0;i<n;i++){
        int num = a[i];
        int cur = query(tree,1,1,MAX,1,num-1);
        if(answ<cur+1){
            answ=cur+1;
        }
        update(tree,1,1,MAX,num,cur+1);
    }

    cout << answ << '\n';

    return 0;
}