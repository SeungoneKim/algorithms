#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int s, int b){
    if(s==0) return b;
    if(s>b) swap(s,b); 

    int k =s;
    s= b%s;
    b=k;

    return gcd(s,b);
}

int main(){
    int a,b;
    cin >> a >> b;

    
    int g = gcd(a,b);
    int l = (a*b)/g;

    cout << g << '\n';
    cout << l << '\n';

    return 0;
}