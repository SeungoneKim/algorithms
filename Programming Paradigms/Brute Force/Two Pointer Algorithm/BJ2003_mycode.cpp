#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int a[10000];

int main(){

    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int left=0,right=0,sum=a[0],answ=0;
    while(right<n){
        if(sum<m){
            right++;
            sum += a[right];
        }
        else if(sum==m){
            answ++;
            right++;
            sum += a[right];
        }
        else if(sum>m){
            if(left==right){
                right++;
                sum += a[right];
            }
            else{
                sum -= a[left];
                left++;
            }
        }
    }

    cout << answ << '\n';

    return 0;
}