#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>lesson(100001);

int lesson_num;

long long calculation(int m){
    long long answ=1;
    long long tmp=0;
    for(int k=0;k<lesson_num;k++){
        if(tmp+lesson[k]<=m){
            tmp+=lesson[k];
        }
        else{
            answ++;
            tmp=lesson[k];
        }
    }
    return answ;
}

int main(){

    int blueray_num;
    cin >> lesson_num >> blueray_num;

    lesson.resize(lesson_num);

    long long sum=0;
    long long maxb=0;
    for(int k=0;k<lesson_num;k++){
        cin >> lesson[k];
        sum += lesson[k];
        if(lesson[k]>maxb) maxb=lesson[k];
    }

    long long left= maxb;
    long long right= sum;
    long long mid=0;
    long long answ=100000000;

    while(left<=right){
        mid = left + (right-left)/2;
        long long sol = calculation(mid);

        if(sol<=blueray_num){
            if(mid<answ) answ=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }

    cout << answ << '\n';

    return 0;
}