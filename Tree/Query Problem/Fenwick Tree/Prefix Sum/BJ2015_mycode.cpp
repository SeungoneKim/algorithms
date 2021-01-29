#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int numbers[200001];
int sum[200001];

int main(){

    int len, goal;
    cin >> len >> goal;

    for(int k=1;k<=len;k++){
        cin >> numbers[k];
    }
    sum[1]=numbers[1];
    for(int k=2;k<=len;k++){
        sum[k]=sum[k-1]+numbers[k];
    }

    long long answ=0;

    map<int,int>cnt;
    cnt[0]=1; // this is because s[0]=0
    for(int k=1;k<=len;k++){
        answ += cnt[sum[k]-goal];
        cnt[sum[k]]++;
    }
    cout << answ << '\n';

    return 0;
}