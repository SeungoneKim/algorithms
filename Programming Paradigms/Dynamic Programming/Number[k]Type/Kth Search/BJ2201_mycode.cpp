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

long long dp[101];
long long dpsum[101];

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    dp[1]=1;
    dp[2]=1;
    dpsum[1]=1;
    dpsum[2]=2;
    for(int i=3;i<=100;i++){
        dp[i]=dp[i-1]+dp[i-2];
        dpsum[i]= dpsum[i-1]+dp[i];
    }

    long long k;
    cin >> k;

    if(k==1){
        cout << "1" << '\n';
        return 0;
    }

    cout << "10";
    int len=0;
    for(int i=2;i<=100;i++){
        if(dpsum[i]>=k){
            len=i;
            break;
        }
    }

    k-=(dpsum[len-1]+1);
    len-=2;
    while(len>0){
        if(k>dpsum[len-1]){
            if(len>=2){
                cout << "10";
            }
            else{
                cout << "1";
            }
            k -=(dpsum[len-1]+1);
            len -=2;
        }
        else{
            cout << "0";
            len -=1;
        }
    }
    cout << '\n';

    return 0;
}