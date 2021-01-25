#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

long long tall[21];
long long binomial[21][21];

int main(){

    binomial[1][1]=1;
    for(int i=1;i<=20;i++){
        binomial[i][0]=1;
    }
    for(int k=2;k<=20;k++){
        for(int i=1;i<=20;i++){
            binomial[k][i] = binomial[k-1][i-1]+binomial[k-1][i];
        }
    }
    
    tall[0]=1;
    tall[1]=1;
    tall[2]=1;
    for(int k=3;k<=20;k++){
        for(int i=1;i<=k;i+=2){
            tall[k]+= tall[i-1]*tall[k-i]*binomial[k-1][i-1];
        }
    }
    

    int tc;
    cin >> tc;

    while(tc--){
        int a;
        cin >> a;
        if(a==1){
            cout << 1 << '\n';
        }
        else{
            cout << tall[a]*2 << '\n';
        }
    }

    return 0;
}