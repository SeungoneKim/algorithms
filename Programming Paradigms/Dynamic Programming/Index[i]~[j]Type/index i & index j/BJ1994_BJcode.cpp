#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int d[2000][2000];
vector<int> a;
int n;
int go(int i, int j){
    if (i > j) {
        return 0;
    } else if (i == j) {
        return 1;
    }
    int &ans = d[i][j];
    if (ans != 0) {
        return ans;
    }
    int diff = a[j] - a[i];
    int next = a[j] + diff;
    int p = lower_bound(a.begin(), a.end(), next) - a.begin();
    if (a[p] == next) {
        return ans = go(j, p) + 1;
    } else {
        return ans = 2;
    }
}
int main(){
    cin >> n;
    a.resize(n);
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    int ans = 1;
    int cnt = 1;
    for (int i=1; i<n; i++) {
        if (a[i] == a[i-1]) {
            cnt++;
            if (cnt > ans) {
                ans = cnt;
            }
        } else {
            cnt=1;
        }
    }
    a.erase(unique(a.begin(),a.end()),a.end());
    n=a.size();
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            int now = go(i,j);
            if (now > ans) {
                ans = now;
            }
        }
    }
    printf("%d\n",ans);
    return 0;
}