#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<pair<int,long long>>numbers(n);
    vector<long long>tmp(n);
    for(int k=0;k<n;k++){
        cin >> tmp[k];
        long long num=tmp[k];
        int ans=0;
        while(num%3==0){
            num /=3;
            ans++;
        }
        numbers[k]={-ans,tmp[k]};
    }

    sort(numbers.begin(),numbers.end());

    for(int k=0;k<n;k++){
        cout << numbers[k].second << ' ';
    }
    cout << '\n';

    return 0;
}