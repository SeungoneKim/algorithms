#include <iostream>
#include <stack>

using namespace std;

int sequence[1001];
int dp[1001];
int before[1001];

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
                if(dp[k]<dp[t]+1){
                    dp[k]=dp[t]+1;
                    before[k]=t;
                }
            }
        }
    }

    int asw=1;
    int idx=1;
    for(int k=1;k<=n;k++){
        if(dp[k]>asw){
            asw=dp[k];
            idx=k;
        }
    }
    
    cout << asw << '\n';
    
    if(asw!=1){
        stack<int> s;
        s.push(sequence[idx]);
        int a = asw;
        a--;

        while(a--){
            s.push(sequence[before[idx]]);
            idx = before[idx];
        }

        while(!s.empty()){
            int tp = s.top();
            s.pop();
            cout << tp << ' ';
        }
        cout << '\n';
    }
    else{
        cout << sequence[idx] << '\n';
    }

    return 0;
}