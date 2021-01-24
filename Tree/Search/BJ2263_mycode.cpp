#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>inorder(100001);
vector<int>inorder_position(100001);
vector<int> postorder(100001);

void solve(int in_fromidx, int in_toidx, int post_fromidx, int post_toidx){
    if(in_fromidx>in_toidx || post_fromidx>post_toidx){
        return;
    }
    int root=postorder[post_toidx];
    int rootidx=inorder_position[root];

    cout << root << ' ';
    int left_length=rootidx-in_fromidx;
    solve(in_fromidx,rootidx-1,post_fromidx,post_fromidx+left_length-1);
    solve(rootidx+1,in_toidx,post_fromidx+left_length,post_toidx-1);
}

int main(){

    int size;
    cin >> size;

    inorder.resize(size);
    inorder_position.resize(size);
    postorder.resize(size+1);

    for(int k=0;k<size;k++){
        cin >> inorder[k];
    }
    for(int k=0;k<size;k++){
        cin >> postorder[k];
    }
    for(int k=0;k<size;k++){
        inorder_position[inorder[k]]=k;
    }

    solve(0,size-1,0,size-1);
    cout << '\n';

    return 0;
}