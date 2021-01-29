#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int l;

void update(vector<long long> &tree, int i, int diff) {
    while (i <= l) {
        tree[i] += diff;
        i += (i & -i);
    }
}
long long sum(vector<long long> &tree, int i) {
    long long ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

long long sum(vector<long long>&tree, int i,int r){
    if(i>r) return 0;
    return sum(tree,r)-sum(tree,i-1);
}

int main(){

    int n;
    cin >> n;
    l=n;
    vector<int>a(n+1);
    vector<long long>tree1(n+1);
    vector<long long>tree2(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long answ=0;

    for(int i=1;i<=n;i++){
        update(tree1,a[i],1);
        update(tree2,a[i],sum(tree1,a[i]+1,n));
        answ += sum(tree2,a[i]+1,n);
    }

    cout << answ << '\n';

    return 0;
}