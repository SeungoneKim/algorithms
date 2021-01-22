#include <iostream>

using namespace std;

long long dp[101];

int main(){
    dp[1]=1,dp[2]=1,dp[3]=1,dp[4]=2,dp[5]=2,dp[6]=3;
    int tc=1;
    cin>> tc;
    
    while(tc--){
        int num=1;
        cin>>num;
        
        for(int i=7;i<=num;i++){
            //if(dp[i]>0)
               // continue;
           // else
                dp[i]=dp[i-1]+dp[i-5];
        }
        
        cout << dp[num]<<endl;
    }
    
    return 0;
}