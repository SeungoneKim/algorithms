#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void init(vector<int>&tree,vector<int>&a,int node, int start, int end){
    if(start==end){
        tree[node]=a[start];
    }
    else{
        init(tree, a, node*2, start, (start+end)/2);
        init(tree, a, node*2+1, (start+end)/2+1, end);
        tree[node]= min(tree[node*2],tree[node*2+1]);
    }
}

int query(vector<int>&tree, int node, int start, int end, int i, int j){
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
        return min(m1,m2);
    }
}

void update(vector<int>&tree, int node, int start, int end, int index, int value){
    if(index<start || end<index) return;
    if(start==end){
        tree[node]=value;
        return;
    }
    update(tree,node*2,start,(start+end)/2,index,value);
    update(tree,node*2+1,(start+end)/2+1,end,index,value);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len;
    cin >> len;
    int h= (int)ceil(log2(len));
    int treesize = (1<<(h+1));

    vector<int>a(len);
    vector<int>tree(treesize);

    for(int k=0;k<len;k++){
        cin >> a[k];
    }
    init(tree,a,1,0,len-1);

    int query_num;
    cin >> query_num;
    while(query_num--){
        int w,a,b;
        cin  >> w >> a >> b;
        if(w==2){
            int answ= query(tree,1,0,len-1,a-1,b-1);
            cout << answ << '\n';
        }
        else{
            update(tree,1,0,len-1,a-1,b);
        }
    }

    return 0;
}