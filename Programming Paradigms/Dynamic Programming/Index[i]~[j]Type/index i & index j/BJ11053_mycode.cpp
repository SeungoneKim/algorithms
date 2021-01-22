#include <iostream>

using namespace std;

int sequence[1001];
int dp[1001]; 

int main(){
    int n;
    cin >> n;

    for(int k=1;k<=n;k++){
        cin >> sequence[k];
    }

    for(int k=1;k<=n;k++){
        dp[k]=1;
    }
    for(int k=2;k<=n;k++){
        for(int t=1;t<k;t++){
            if(sequence[t]<sequence[k]){
                dp[k] = max(dp[k],dp[t]+1);
            }
        }
    }

    int asw=1;
    for(int k=1;k<=n;k++){
        asw = max(dp[k],asw);
    }
    
    cout << asw << '\n';

    return 0;
}