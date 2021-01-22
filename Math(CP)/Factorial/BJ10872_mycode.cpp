#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    int answ=1;
    for(int k=n;k>=1;k--){
        answ *= k;
    }

    cout << answ << '\n';

    return 0;
}