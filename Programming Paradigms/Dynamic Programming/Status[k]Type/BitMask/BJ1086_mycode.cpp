#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>

using namespace std;

int mod;
int n;
vector<int>arr(15);
vector<int> ten(51);
long long dp[1<<15][100];

long long calc(int a, int b){
    long long ans=1;
    while(b>0){
        if(b%2==1){
            ans *=a;
            ans %= mod;
        }
        a = a*a;
        a %= mod;
        b /=2;
    }
    return ans;
}

long long gcd(long long s, long long b){
    if(s==0) return b;

    int k =s;
    s= b%s;
    b=k;

    return gcd(s,b);
}

long long go(int order,int curmod,int exp,int state){
    if(order==n && curmod==0){
        return 1;
    }
    else if(order==n){
        return 0;
    }
    
    long long& answ= dp[state][curmod];
    if(answ!=-1) return answ;
    answ=0;
    for(int i=0;i<n;i++){
        if((state&(1<<i))==0){
            int len = to_string(arr[i]).length();
            int nextmod= (curmod+ ((arr[i])*calc(ten[i],exp))%mod)%mod;
            // cout << order+1 << ' ' << nextmod << ' ' << exp+len << ' ' << (state|(1<<i)) << '\n';
            answ += go(order+1,nextmod,exp+len,state|(1<<i));
        }
    }
    // cout << "final " << order << ' ' << state << ' ' << answ << '\n';
    return answ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    cin >> mod;

    ten[0] = 1;
    for (int i=1; i<=50; i++) {
        ten[i] = ten[i-1] * 10;
        ten[i] %= mod;
    }
    
    for(int i=0;i<n;i++){
        arr[i] %= mod;
    }
    memset(dp,-1,sizeof(dp));

    long long denom= go(0,0,0,0);
    // cout << denom << '\n';

    if(denom==0){
        cout << "0/1" << '\n';
    }

    else if(n>=12){
        long long nom=1;
        for(int i=2;i<=12;i++){
            nom *= i;
        }
        long long g= gcd(denom,nom);
        denom /= g;
        nom /= g;
        
        for(int i=13;i<=n;i++){
            nom *= i;
            g= gcd(denom,nom);
            if(g!=1){
                denom /= g;
                nom /= g;
            }
        }
        
        cout << denom << "/" << nom << '\n';
    }
    else{
        long long nom=1;
        for(int i=2;i<=n;i++){
            nom *= i;
        }
        long long g= gcd(denom,nom);

        cout << denom/g << "/" << nom/g << '\n';
    }
    

    return 0;
}