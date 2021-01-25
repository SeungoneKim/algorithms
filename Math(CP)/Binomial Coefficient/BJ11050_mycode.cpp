#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int n,m;
    cin >> n >> m;

    int num=1;
    int denum=1;

    for(int k=n;k>=1;k--){
        num *= k;
    }
    for(int t=m;t>=1;t--){
        denum *= t;
    }
    for(int t=n-m;t>=1;t--){
        denum *= t;
    }

    int answ= num / denum;
    cout << answ << '\n';

    return 0;
}