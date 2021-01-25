#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int a[1000];
int d[1000][1000];

int go(int i,int j){
    if(i>=j){
        return 0;
    }
    int& answ=d[i][j];
    if(answ!=-1){
        return answ;
    }
    answ = go(i+1,j);
    for(int k=i+1;k<=j;k++){
        int cur=0;
        if(a[i]==a[k]){
            cur = go(i+1,k-1) + go(k+1,j)+1;
        }
        if(answ<cur){
            answ=cur;
        }
    }
    return answ;
}

int main(){

    int n;
    cin >> n;
    for (int i=0; i<n; i++) {
        cin >> a[i];
    }
    memset(d,-1,sizeof(d));
    cout << go(0, n-1) << '\n';

    return 0;
}