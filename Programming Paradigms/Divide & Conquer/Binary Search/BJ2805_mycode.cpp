#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
int trees[1000001];

long long calc(int n){
    long long answ=0;
    for(int k=1;k<=num;k++){
        if(trees[k]>n){
            answ += trees[k]-n;
        }
    }
    return answ;
}

int main(){

    int goal;
    cin >> num >> goal;

    long long maxh=0;
    for(int k=1;k<=num;k++){
        cin >> trees[k];
        if(trees[k]>maxh) maxh=trees[k];
    }

    long long left=1;
    long long right= maxh;
    long long mid=0;
    long long answ=0;

    while(left<=right){
        mid = (left+right)/2;
        long long sol = calc(mid);
        if(sol<goal){
            right=mid-1;
        }
        else{
            answ = mid;
            left=mid+1;
        }
    }

    cout << answ << '\n';

    return 0;
}