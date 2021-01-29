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

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<pair<int,long long>>a(n);
    for(int i=0;i<n;i++){
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(),a.end());

    for(int i=1;i<n;i++){
        a[i].second += a[i-1].second;
    }
    long long total=a[n-1].second;
    long long mid=(total+1)/2;

    long long answ=-1;
    for(int i=0;i<n;i++){
        if(a[i].second>=mid){
            answ=a[i].first;
            break;
        }
    }

    cout << answ << '\n';

    return 0;
}