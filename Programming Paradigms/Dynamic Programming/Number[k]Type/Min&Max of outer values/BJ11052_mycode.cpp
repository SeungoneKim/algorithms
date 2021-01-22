#include <iostream>
#include <vector>

using namespace std;

vector<int> v(10001);
int dp[1001];

int main(){
    int n;
    cin >> n;

    for(int k=1;k<=n;k++){
        cin >> v[k];
    }
    //initilaization
    for(int k=1;k<=n;k++){
        dp[k]=v[k];
    }

    for(int k=2;k<=n;k++){
        for(int t=1;t<k;t++){
            if(dp[k]<dp[t]+v[k-t])
                dp[k]=dp[t]+v[k-t];
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
// top-down version
/*
#include <iostream>
#include <vector>

using namespace std;

int dp[1001];
vector <int> price;

int mostexpensive (int num){
    if(num == 0) return 0;
    if(dp[num]>0) return dp[num];
    
    dp[num] = price[num];
    for(int i=1;i<=num;i++){
        if(dp[num]<mostexpensive(num-i)+price[i])
            dp[num] = mostexpensive(num-i)+price[i];
    }
    
    return dp[num];
}

int main(){
    int numofcard;
    cin >> numofcard;
    price.reserve(numofcard+1);
    
    for(int i=1;i<=numofcard;i++){
        cin >> price[i];
    }
    
    cout << mostexpensive(numofcard);
    
    return 0;
}
*/