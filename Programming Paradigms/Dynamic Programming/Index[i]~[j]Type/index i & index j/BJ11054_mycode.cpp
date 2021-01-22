#include <iostream>

using namespace std;

int sequence[1001];
int growdp[1001];
int shrinkdp[1001];
int dp[1001];

int main(){
    int len;
    cin >> len;

    for(int k=1;k<=len;k++){
        cin >> sequence[k];
    }

    for(int k=1;k<=len;k++){
        growdp[k]=1;
        shrinkdp[k]=1;
    }

    for(int k=2;k<=len;k++){
        for(int t=1;t<k;t++){
            if(sequence[t]<sequence[k]){
                growdp[k] = max(growdp[k],growdp[t]+1);
            }
        }
    }

    for(int k=len;k>=1;k--){
        for(int t=k-1;t>=1;t--){
            if(sequence[t]>sequence[k]){
                shrinkdp[t] = max(shrinkdp[t],shrinkdp[k]+1);
            }
        }
    }

    for(int k=1;k<=len;k++){
        dp[k] = growdp[k]+shrinkdp[k]-1;
    }

    int answ = dp[1];
    for(int k=2;k<=len;k++){
        answ = max(answ,dp[k]);
    }
    
    cout << answ << '\n';

    return 0;
}