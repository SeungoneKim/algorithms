#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;
int l;
long long mod=1000000007LL;

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

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    l=200000;
    long long answ=1;

    vector<long long>cnt(l+1);
    vector<long long>dist(l+1);
    for(int i=0;i<n;i++){
        long long x;
        cin >> x;
        x++;
        
        if(i!=0){
            long long price = x*(sum(cnt,1,x-1)-sum(cnt,x+1,l))-(sum(dist,1,x-1)-sum(dist,x+1,l));
            price %= mod;
            answ= (answ*price)%mod;
        }
        
        update(cnt,x,1);
        update(dist,x,x);
    }
    
    cout << answ << '\n';

    return 0;
}