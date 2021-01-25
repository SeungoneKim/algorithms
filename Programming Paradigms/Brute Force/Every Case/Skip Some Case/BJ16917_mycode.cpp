#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){

    int a,b,c;
    int x,y;
    cin >> a >> b >> c >> x >> y;

    long long answ= a*x+b*y;
    for(int i=2;i<=100000;i++){
        long long tmp= a*max(0,x-i)+b*max(0,y-i)+c*i*2;
        if(tmp<answ) answ=tmp;
    }

    cout << answ << '\n';

    return 0;
}