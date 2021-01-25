#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

long long calc(int a, int b, int c){
    if(b==0) return 1LL;
    else if(b==1) return a%c;
    else if(b%2==0){
        long long temp=calc(a,b/2,c)%c;
        return (temp*temp)%c;
    }
    else{
        return (a*(calc(a,b-1,c)%c))%c;
    }
}

int main(){

    long long a,b,c;
    cin >> a >> b >> c;

    cout << calc(a,b,c)%c << '\n';

    return 0;
}