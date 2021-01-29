#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int tree[1000000]; // tree[i] : i를 마지막으로 하는 가장 긴 증가하는 부분 수열의 길이

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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len, query_num;
    cin >> len >> query_num;
    int h= (int)ceil(log2(len));
    int treesize = (1<<(h+1));

    vector<int>a(len);
    vector<int>tree(treesize);

    for(int k=0;k<len;k++){
        cin >> a[k];
    }
    init(tree,a,1,0,len-1);


    while(query_num--){
        int a,b;
        cin >> a >> b;
        int answ= query(tree,1,0,len-1,a-1,b-1);
        cout << answ << '\n';
    }

    return 0;
}