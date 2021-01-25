#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int d[301][301];

int go(int n,int m){
    if(n==1 && m==1){
        return 0;
    }
    int& answ=d[n][m];
    if(answ!=-1){
        return answ;
    }
    answ=100000000;
    for(int i=1;i<n;i++){
        if(answ>go(i,m)+go(n-i,m)+1){
            answ=go(i,m)+go(n-i,m)+1;
        }
    }
    for(int i=1;i<m;i++){
        if(answ>go(n,i)+go(n,m-i)+1){
            answ=go(n,i)+go(n,m-i)+1;
        }
    }
    return answ;
}

int main(){

    int n,m;
    cin >> n >> m;
    memset(d,-1,sizeof(d));

    cout << go(n,m) << '\n';

    return 0;
}