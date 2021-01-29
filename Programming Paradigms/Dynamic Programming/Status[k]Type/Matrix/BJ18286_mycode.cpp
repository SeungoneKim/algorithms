#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;
const long long mod = 1000000007;
using matrix = vector<vector<long long>>;
matrix operator * (const matrix &a, const matrix &b) {
    int n = a.size();
    matrix c(n, vector<long long>(n));
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            for (int k=0; k<n; k++) {
                c[i][j] += a[i][k] * b[k][j];
                c[i][j] %= mod;
            }
        }
    }
    return c;
}

int isset(int state,int idx){
    if(state & (1<<idx)){
        return 1;
    }
    else{
        return 0;
    }
}

bool ok(int pstate,int state,int m){
    for(int i=0;i<m-1;i++){
        int color11 = isset(pstate,i);
        int color12 = isset(pstate,i+1);
        int color21 = isset(state,i);
        int color22 = isset(state,i+1);
        if(color11 == color12 && color12==color21 && color21==color22){
            return false;
        }
    }
    return true;
}


int main(){

    long long n;
    int m;
    cin >> n >> m;
    int size= (1<<m);

    matrix ans(size,vector<long long>(size));
    matrix a(size,vector<long long>(size));
    for(int i=0;i<size;i++){
        ans[i][i]=1;
        for(int j=0;j<size;j++){
            if(ok(i,j,m)){
                a[i][j]=1;
            }
        }
    }
    n-=1;
    while(n>0){
        if(n%2==1){
            ans = ans * a;
        }
        a = a*a;
        n/=2;
    }
    long long sum=0;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            sum += ans[i][j];
            sum %= mod;
        }
    }

    cout << sum << '\n';
    
    return 0;
}