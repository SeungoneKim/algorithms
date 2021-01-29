#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cmath>

using namespace std;

int sum(vector<int> &tree, int x) {
    int ans = 0;
    for (int i=x; i>0; i -= i&-i) {
        ans += tree[i];
    }
    return ans;
}
void update(vector<int> &tree, int x, int diff) {
    for (int i=x; i<tree.size(); i += i&-i) {
        tree[i] += diff;
    }
}
int sum(vector<int> &tree, int x, int y) {
    return sum(tree, y) - sum(tree, x-1);
}
int main(){

    int n;
    cin >> n;
    
    vector<int>a(n);
    map<int,int>m;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m[a[i]]=i+1;
    }    

    vector<int>tree(n+1);
    for(int i=1;i<=n;i++){
        update(tree,i,1);
    }
    int left = 1;
    int right = n;
    for(int i=1;i<=n;i++){
        if(i%2!=0){
            update(tree,m[left],-1);
            cout << sum(tree,1,m[left]) << '\n';
            left++;
        }
        else{
            update(tree,m[right],-1);
            cout << sum(tree,m[right],n) << '\n';
            right--;
        }
    }

    return 0;
}