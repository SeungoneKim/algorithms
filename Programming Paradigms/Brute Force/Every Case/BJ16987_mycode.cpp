#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int n;
int s[10];
int w[10];

int go(int idx){
    if(idx==n){
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]<=0){
                cnt++;
            }
        }
        return cnt;
    }
    if(s[idx]<=0){
        return go(idx+1);
    }
    int answ=0;
    bool ok=false;
    for(int j=0;j<n;j++){
        int i=idx;
        if(i==j) continue;
        if(s[j]>0){
            ok=true;
            s[i]-=w[j];
            s[j]-=w[i];
        
            int temp=go(idx+1);
            if(answ<temp) answ=temp;

            s[i] += w[j];
            s[j] += w[i];
        }
    }
    if(!ok){
        return go(idx+1);
    }
    return answ;
}

int main(){

    cin >> n;
    for(int k=0;k<n;k++){
        int a,b;
        cin >> a >> b;
        s[k]=a;
        w[k]=b;
    }
    cout << go(0) << '\n';

    return 0;
}