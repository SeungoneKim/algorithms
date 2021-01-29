#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

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
int kth(vector<int> &tree, int node, int start, int end, int k) {
    if (start == end) {
        tree[node] = 0;
        return start;
    }
    int ans = 0;
    if (k <= tree[node*2]) {
        ans = kth(tree, node*2, start, (start+end)/2, k);
    } else {
        ans = kth(tree, node*2+1, (start+end)/2+1, end, k-tree[node*2]);
    }
    tree[node] = tree[node*2] + tree[node*2+1];
    return ans;
}

int main(){

    int n;
    cin >> n;

    vector<int>black(n);
    vector<int>gray(n);
    vector<int>white(n);

    for(int i=0;i<n;i++){
        cin >> black[i];
    }
    for(int i=0;i<n;i++){
        cin >> gray[i];
    }
    for(int i=0;i<n;i++){
        cin >> white[i];,
    }
    int height=0;
    for(int i=0;i<n;i++){
        if(height<black[i]+gray[i]+white[i]+1){
            height= black[i]+gray[i]+white[i]+1;
        }
    }
    vector<int>y(height+1);
    y[0]=0;
    y[1]=n;
    for(int i=0;i<n;i++){
        y[black[i]+1]+=1;
        y[black[i]+gray[i]+1]+=3;
        y[black[i]+gray[i]+white[i]+1]-=5;
    }
    vector<int>x(height+1);
    for(int i=1;i<=height;i++){
        x[i] = x[i-1]+y[i];
    }
    int h = (int)ceil(log2(height));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    init(tree, 1, 1, height);
    int query;
    cin >> query;

    while(query--){
        int t;
        cin >> t;
        int k= kth(tree,1,1,height,h);
        cout << x[k] << '\n';
    }
    
    


    return 0;
}