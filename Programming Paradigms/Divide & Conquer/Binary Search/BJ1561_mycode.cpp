#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long ride[10001];
long long ridenum;

long long calculation(long long m){
    long long cnt=ridenum;
    for(long long k=0;k<ridenum;k++){
        cnt+= m/ride[k];
    }
    return cnt;
}

int main(){

    long long child;
    cin >> child >> ridenum;

    for(int k=0;k<ridenum;k++){
        cin >> ride[k];
    }

    if(child<=ridenum){
        cout << child << '\n';
        return 0;
    }

    long long left= 0;
    long long right= 2000000000LL * 1000000LL;
    long long mid= 0;
    long long answ= 0;

    while(left<=right){
        mid = left+(right-left)/2;
        long long sol = calculation(mid);
        // cout << mid << ' ' << sol << '\n';
        if(child<=sol){
            answ=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }

    long long standard=calculation(answ-1);
    long long answ_of_ride=0;
    // cout << answ << ' ' <<standard << '\n';
    
    for(long long k=0;k<ridenum;k++){
        if(answ%ride[k]==0){
            answ_of_ride++;
        }
        if(standard+answ_of_ride==child){
            cout << k+1 << '\n';
            return 0;
        }
    }

    return 0;
}