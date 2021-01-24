#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int housenum;
int housecoor[200001];

long long calculation(int n){
    int last=housecoor[1];
    long long cnt=1;
    for(int k=2;k<=housenum;k++){
        if(housecoor[k]-last>=n){
            cnt++;
            last=housecoor[k];
        }
    }
    return cnt;
}

int main(){

    int routernum;
    cin >> housenum >> routernum;

    for(int k=1;k<=housenum;k++){
        cin >> housecoor[k];
    }
    sort(housecoor+1,housecoor+housenum+1);

    long long left=1;
    long long right= housecoor[housenum]-housecoor[1];
    long long mid=0;
    long long answ=0;

    while(left<=right){
        long long mid = (left+right)/2;
        long long sol = calculation(mid);
        if(sol>=routernum){
            if(mid>answ) answ=mid;
            left= mid+1;
        }
        else{
            right=mid-1;
        }
    }
    cout << answ << '\n';

    return 0;
}