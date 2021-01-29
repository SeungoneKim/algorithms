#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int a[100001];
int tree[200001];
int l;

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

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int n,m;
        cin >> n >> m;
        vector<int> tree(n+m+1);
        vector<int> position(n+1);
        l=n+m;
        for(int i=1;i<=n;i++){
            update(tree,m+i,1);
            position[i]=m+i;
        }

        for(int i=0;i<m;i++){
            int target;
            cin >> target;
            cout << sum(tree,position[target]-1) << ' ';
            update(tree,position[target],-1);
            position[target]=m-i;
            update(tree,position[target],1);
        }

        memset(a,0,sizeof(a));
    }


    return 0;
}