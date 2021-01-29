#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

long long numbers[1000001];
long long sum[1000001];

int main(){

    int len,goal;
    cin >> len >> goal;

    for(int k=1;k<=len;k++){
        cin >> numbers[k];
    }
    sum[1]=numbers[1];
    for(int k=2;k<=len;k++){
        sum[k] = sum[k-1]+numbers[k];
    }

    long long answ=0;

    map<int,long long>cnt;
    cnt[0]=1;
    for(int k=1;k<=len;k++){
        answ += cnt[(sum[k]%goal)];
        cnt[sum[k]%goal]++;
    }

    cout << answ << '\n';

    return 0;
}