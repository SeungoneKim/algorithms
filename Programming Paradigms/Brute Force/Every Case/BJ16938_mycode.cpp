#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n,l,r,x;
bool check[15];

int go(vector<int>& a,int idx){
    if(idx==n){
        int cnt=0;
        int sum=0;
        int hard=-1;
        int easy=-1;
        for(int i=0;i<n;i++){
            if(check[i]==false) continue;
            sum += a[i];
            cnt++;
            if(hard==-1 || hard<a[i]) hard=a[i];
            if(easy==-1 || easy>a[i]) easy=a[i];
        }
        if(cnt>=2 && l<=sum && sum<=r && hard-easy>=x){
            return 1;
        }
        else return 0;
    }
    check[idx]=true;
    int cnt1=go(a,idx+1);
    check[idx]=false;
    int cnt2=go(a,idx+1);
    return cnt1+cnt2;
}

int main(){

    cin >> n >> l >> r >> x;

    vector<int>problems(n);
    for(int k=0;k<n;k++){
        cin >> problems[k];
    }

    cout << go(problems,0) << '\n';

    return 0;
}