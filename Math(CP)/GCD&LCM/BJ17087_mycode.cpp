#include <iostream>

using namespace std;

int numarr[100001];

int gcd(int s, int b){
    if(s==0) return b;

    int k =s;
    s= b%s;
    b=k;

    return gcd(s,b);
}

int main(){
    int start, pn;
    cin >> pn >> start;

    int a=0;
    for(int k=0;k<pn;k++){
        cin >> a;
        int putin = start-a;
        putin<0 ? putin = -putin : putin = putin;
        numarr[k] = putin;
    }

    int answ=gcd(numarr[0],numarr[1]);
    for(int k=2;k<pn;k++){
        answ = gcd(answ,numarr[k]);
    }

    cout << answ << '\n';

    return 0;
}