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

void init(vector<int>&a, vector<vector<int>>&tree,int node, int start,int end){
    if(start==end){
        tree[node].push_back(a[start]);
        return;
    }
    int mid=(start+end)/2;
    init(a,tree,node*2,start,mid);
    init(a,tree,node*2+1,mid+1,end);

    merge(tree[node*2].begin(),tree[node*2].end(),tree[node*2+1].begin(),tree[node*2+1].end(),back_inserter(tree[node]));
}

int query(vector<vector<int>>&tree,int node, int start, int end, int i, int j, int k){
    if(i>end || j<start) return 0;

    if(i<=start && end<=j){
        return tree[node].size()-(upper_bound(tree[node].begin(),tree[node].end(),k)-tree[node].begin());
    }
    int mid=(start+end)/2;

    return query(tree,node*2,start,mid,i,j,k)+query(tree,node*2+1,mid+1,end,i,j,k);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    
    int h=ceil(log2(n+1));
    int treesize=(1<<(h+1));

    vector<vector<int>>tree(treesize);
    init(a,tree,1,0,n-1);

    int querynum;
    cin >> querynum;
    int answ=0;
    while(querynum--){
        int from,to,k;
        cin >> from >> to >> k;
        int revised_from=from^answ;
        int revised_to=to^answ;
        int revised_k=k^answ;

        answ= query(tree, 1,0,n-1,revised_from-1,revised_to-1,k);
        
        cout << answ << '\n';
    }

    return 0;
}