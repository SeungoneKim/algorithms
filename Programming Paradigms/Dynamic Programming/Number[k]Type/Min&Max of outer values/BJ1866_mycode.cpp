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

int dp[3001];

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a.begin()+1,a.end());

    int helicopter_cost,truck_cost;
    cin >> truck_cost >> helicopter_cost;

    // we handle prefix sum first
    vector<int>s(n+1);
    s[1]=a[1];
    for(int i=2;i<=n;i++){
        s[i]= s[i-1]+a[i];
    }

    // dynamic programming
    dp[1]= min(helicopter_cost,a[1]*truck_cost);
    for(int i=2;i<=n;i++){
        // moving nth element with truck
        dp[i] = dp[i-1]+ a[i]*truck_cost; // ith element in a[i-1]

        // moving nth element with helicopter, decide from which element to nth element the helicopter will move together
        for(int t=1;t<=i;t++){
            int mid= (i+t)/2;
            int cost=helicopter_cost;
            cost += ( (a[mid]*(mid-t+1)) - (s[mid]-s[t-1]) )*truck_cost;
            cost += ( (s[i]-s[mid]) - (a[mid]*(i-mid)) )*truck_cost;
            dp[i]= min(dp[i],dp[t-1]+cost);
        }
    }

    cout << dp[n] << '\n';

    return 0;
}