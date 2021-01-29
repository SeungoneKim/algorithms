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

const long long bignumber=1000000000000LL;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,k;
    cin >> n >> k;

    vector<int>a(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }

    vector<int> dp(n+1);
    vector<long long> cnt(n+1);

    for(int i=n;i>=1;i--){
        dp[i]=1;
        cnt[i]=1;
        for(int j=i+1;j<=n;j++){
            if(a[i]<a[j]){
                if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    cnt[i]=cnt[j];
                }
                else if(dp[i]==dp[j]+1){
                    cnt[i]+=cnt[j];
                }
                /*
                if(cnt[i]>=bignumber){
                    cnt[i]=bignumber;
                }
                */
            }
        }
    }
    
    int len= *max_element(dp.begin()+1,dp.end());

    int start=0;
    vector<int>answ;
    while(len>0){
        int checking_starting_point=-1;
        long long sum=0;
        vector<pair<int,int>>checker;
        for(int i=start+1;i<=n;i++){
            if( (a[start]<a[i]) && (dp[i]==len) ){
                checker.push_back({a[i],i});
            }
        }
        sort(checker.begin(),checker.end());
        for(auto& p: checker){
            int curcheck=p.second;
            sum+=cnt[curcheck];
            if(k<=sum){
                answ.push_back(a[curcheck]);
                checking_starting_point=curcheck;
                k-= (sum-cnt[curcheck]);
                break;
            }
        }
        if(checking_starting_point==-1){
            cout << -1 << '\n';
            return 0;
        }
        start=checking_starting_point;
        len--;
    }

    for(int x: answ){
        cout << x << ' ';
    }
    cout << '\n';

    return 0;
}