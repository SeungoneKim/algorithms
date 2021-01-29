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

int n,m;
long long k;
long long dp[11][221][221]; // [sequence length][total sum][first used number]
                    // think of dp as adding numbers in the front


void printer(int idx,int totalsum,int last,long long kth){
    if(idx<=0){
        return;
    }
    long long curkth=0;
    for(int i=last;i<=m;i++){
        if(kth < curkth+dp[idx][totalsum][i]){
            cout << i << ' ';
            printer(idx-1,totalsum-i,i,kth-curkth);
            break;
        }
        curkth += dp[idx][totalsum][i];
    }
    return;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;

    for(int i=1;i<=m;i++){
        dp[1][i][i]=1;
    }
    // sequence length
    for(int i=2;i<=n;i++){
        // total sum
        for(int t=i;t<=m;t++){
            // first used number at length n sequence
            for(int l=1;l<=m;l++){
                // first used number at length n-1 sequence
                for(int p=l;p<=m;p++){
                    if(t-l>=1)
                        dp[i][t][l] += dp[i-1][t-l][p];
                }
            }
        }
    }

    printer(n,m,1,k-1);

    return 0;
    
}