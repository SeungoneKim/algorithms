#include <iostream>

using namespace std;

int gcd(int s, int b){
    if(s==0) return b;

    int k =s;
    s= b%s;
    b=k;

    return gcd(s,b);
}

int main(){
    int tc;
    cin >> tc;

    while(tc--){
        int a,b;
        cin >> a >> b;

        int g= gcd(a,b);
        int l = (a/g)*(b/g)*g;

        cout << l << '\n';
    }

    return 0;
}