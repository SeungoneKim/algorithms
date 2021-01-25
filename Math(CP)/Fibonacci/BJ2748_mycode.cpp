#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

long long d[91];

int main(){

    int n;
    cin >> n;

    d[0]=0;
    d[1]=1;
    for(int k=2;k<=90;k++){
        d[k] = d[k-1]+d[k-2];
    }

    cout << d[n] << '\n';

    return 0;
}