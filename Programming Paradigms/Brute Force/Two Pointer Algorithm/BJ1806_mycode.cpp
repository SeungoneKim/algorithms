#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int a[100000];

int main(){

    int n,m;
    cin >> n >> m;

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    int left=0,right=0,sum=a[0],answ=1000000000;
    while(right<n){
        if(sum<m){
            right++;
            sum += a[right];
        }
        else if(sum==m){
            if(right-left+1<answ){
                answ=right-left+1;
            }
            right++;
            sum += a[right];
        }
        else if(sum>m){
            if(right-left+1<answ){
                answ=right-left+1;
            }
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
    if(answ==1000000000){
        answ=0;
    }
    cout << answ << '\n';

    return 0;
}