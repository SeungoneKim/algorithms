#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    long long size;
    cin >> size;
    long long k;
    cin >> k;

    long long left=1;
    long long right=size*size;
    long long mid=0;
    long long answ=0;

    while(left<=right){
        mid= left+(right-left)/2;
        long long sol =0;
        for(long long t=1;t<=size;t++){
            sol += min(size,mid/t);
        }
        // cout << mid << ' ' << sol << '\n';
        if(sol>=k){
            answ=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout << answ << '\n';

    return 0;
}