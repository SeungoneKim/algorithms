#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long d[1500001];

int main(){

    int n;
    cin >> n;

    n %= 1500000;

    d[0]=0;d[1]=1;
    for(int k=2;k<=1500000;k++){
        d[k] = (d[k-1]+d[k-2])%1000000;
    }

    cout << d[n] << '\n';

    return 0;
}