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

int MAX=100000;

void init(vector<int>&tree,vector<int>&a,int node, int start, int end){
    if(start==end){
        tree[node]=start;
    }
    else{
        init(tree, a, node*2, start, (start+end)/2);
        init(tree, a, node*2+1, (start+end)/2+1, end);
        if(a[tree[2*node]]>=a[tree[2*node+1]]){
            tree[node]=tree[2*node];
        }
        else{
            tree[node]=tree[2*node+1];
        }
    }
}
void update(vector<int>&tree, vector<int>&a, int node, int start, int end, int index, int value){
    if(index<start || end<index) return;
    if(start==end && start==index){
        a[tree[node]]=value;
        return;
    }
    else if(start==end){
        return;
    }
    update(tree,a,node*2,start,(start+end)/2,index,value);
    update(tree,a,node*2+1,(start+end)/2+1,end,index,value);
    if(a[tree[2*node]]>a[tree[node]]){
        tree[node]=tree[2*node];
    }
    if(a[tree[2*node+1]]>a[tree[node]]){
        tree[node]=tree[2*node+1];
    }
}
int query(vector<int>&tree, vector<int>&a, int node, int start, int end, int i, int j){
    if(i>end || j<start) return -1;
    if(i<=start && end<=j) return tree[node];
    int m1=query(tree,a,2*node,start,(start+end)/2,i,j);
    int m2=query(tree,a,2*node+1,(start+end)/2+1,end,i,j);
    if(m1==-1 && m2==-1){
        return -1;
    }
    if(m1==-1){
        return m2;
    }
    else if(m2==-1){
        return m1;
    }
    else{
        if(a[m1]>=a[m2]){
            return m1;
        }
        else{
            return m2;
        }
    }
}
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    int querynum;
    cin >> querynum;

    int h = (int)ceil(log2(n+1));
    int tree_size = (1 << (h+1));
    vector<int> tree(tree_size);
    init(tree,a,1,1,n);

    while(querynum--){
        int d;
        cin >> d;
        if(d==1){
            int b,c;
            cin >> b >> c;
            update(tree,a,1,1,n,b,c);
        }
        else{
            int b,c;
            cin >> b >> c;
            int maxidx = query(tree,a,1,1,n,b,c);
            int leftidx=maxidx;
            int rightidx=maxidx;
            if((maxidx>b) && (maxidx<c)){
                leftidx = query(tree,a,1,1,n,b,maxidx-1);
                rightidx = query(tree,a,1,1,n,maxidx+1,c);
                if(a[leftidx]<=a[rightidx]){
                    cout << a[rightidx]+a[maxidx] << '\n';
                }
                else{
                    cout << a[leftidx]+a[maxidx] << '\n';
                }
            }
            else if(maxidx==b){
                rightidx = query(tree,a,1,1,n,maxidx+1,c);
                cout << a[maxidx]+a[rightidx] << '\n';
            }
            else{
                leftidx = query(tree,a,1,1,n,b,maxidx-1);
                cout << a[maxidx]+a[leftidx] << '\n';
            }
            

        }
    }

    return 0;
}