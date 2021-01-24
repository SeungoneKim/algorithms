#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k;
int lan[10001];

long long calculation(int p){
    long long answ=0;
    for(int t=1;t<=k;t++){
        answ+= lan[t]/p;
    }
    return answ;
}

int main(){

    int n;
    cin >> k >> n;

    long long sum=0;
    for(int t=1;t<=k;t++){
        cin >> lan[t];
        sum += lan[t];
    }

    long long left=1;
    long long right=sum/n;
    long long ans=0;

    while(left<=right){
        long long mid = (left+right)/2;
        long long sol = calculation(mid); // 문제의 조건에 맞는지 검사하는 함수

        // 정답을 더 크게 해야하는지 작게해야하는지 판단하는 조건문
        if(sol<n){
            right = mid-1;
        }
        else{
            ans=mid;
            left=mid+1;
        }
    }
    cout << ans << '\n';

    return 0;
}