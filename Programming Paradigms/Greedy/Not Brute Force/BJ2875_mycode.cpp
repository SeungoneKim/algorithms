#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int girl,boy,intern;
    cin >> girl >> boy >> intern;

    int answ= min(boy,(girl+boy-intern)/3);
    answ = min(girl/2,answ);
    cout << answ << '\n';

    return 0;
}