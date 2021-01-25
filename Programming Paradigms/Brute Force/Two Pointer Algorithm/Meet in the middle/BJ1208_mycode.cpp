#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int a[1000001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,s;
    cin >> n >> s;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int m=n/2;
    n-=m;

    vector<int>first(1<<n);
    for(int i=0;i<(1<<n);i++){
        for(int k=0;k<n;k++){
            if(i&(1<<k)){
                first[i] += a[k];
            }
        }
    }
    vector<int>second(1<<m);
    for(int i=0;i<(1<<m);i++){
        for(int k=0;k<m;k++){
            if(i&(1<<k)){
                second[i] += a[k+n];
            }
        }
    }

    sort(first.begin(),first.end());
    sort(second.begin(),second.end());
    reverse(second.begin(),second.end());

    n=(1<<n);
    m=(1<<m);
    int left=0,right=0;
    long long answ=0;
    while(left<n && right<m){
        if(first[left]+second[right]==s){
            long long c1=1;
            long long c2=1;
            left++; right++;
            while(left<n && first[left]==first[left-1]){
                c1++;
                left++;
            }
            while(right<m && second[right]==second[right-1]){
                c2++;
                right++;
            }
            answ += c1*c2;
        }
        else if(first[left]+second[right]<s){
            left++;
        }
        else{
            right++;
        }
    }
    if(s==0){
        answ--;
    }
    cout << answ << '\n';

    return 0;
}