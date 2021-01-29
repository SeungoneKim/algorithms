#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int l;
int a[100001];

void update(vector<int> &tree, int i, int diff) {
    while (i <= l) {
        tree[i] += diff;
        i += (i & -i);
    }
}
int sum(vector<int> &tree, int i) {
    int ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

int sum(vector<int>&tree, int i,int r){
    if(i>r) return 0;
    return sum(tree,r)-sum(tree,i-1);
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    l=n;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    vector<int>tree(n+1);
    for(int i=1;i<=n;i++){
        if(a[i]%2==0){
            update(tree,i,1);
        }
    }

    int query;
    cin >> query;
    while(query--){
        int type, x, y;
        cin >> type >> x >> y;

        if(type==1){
            if((a[x]%2==0) && (y%2!=0)){
                update(tree,x,-1);
            }
            else if((a[x]%2!=0) && (y%2==0)){
                update(tree,x,1);
            }
            a[x]=y;
        }
        else if(type==2){
            cout << sum(tree,x,y) << '\n';
        }
        else{
            cout << (y-x+1)-sum(tree,x,y) << '\n';
        }

    }


    return 0;
}