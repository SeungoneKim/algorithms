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

long long sum(vector<long long> &tree, int x) {
    long long ans = 0;
    for (int i=x; i>0; i -= i&-i) {
        ans += tree[i];
    }
    return ans;
}
void update(vector<long long> &tree, int x, long long diff) {
    for (int i=x; i<tree.size(); i += i&-i) {
        tree[i] += diff;
    }
}
void update(vector<long long> &tree, int x, int y, long long diff) {
    update(tree, x, diff);
    update(tree, y+1, -diff);
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long>a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    vector<long long>tree(n+2);

    int query;
    cin >> query;
    while(query--){
        int which;
        cin >> which;
        if(which==1){
            int from,to,val;
            cin >> from >> to >> val;
            update(tree,from,to,val);
        }
        else{
            int idx;
            cin >> idx;
            long long diff= sum(tree,idx);
            cout << diff+a[idx] << '\n';
        }
    }
    return 0;
}