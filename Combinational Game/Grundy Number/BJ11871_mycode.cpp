#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int main(){

    int n;
    cin >> n;
    int answ=0;
    while(n--){
        int tmp;
        cin >> tmp;
        if(tmp%2==0)
            answ ^= (tmp/2)-1;
        else
            answ ^= (tmp+1)/2;
    }

    if(answ!=0){
        cout << "koosaga" << '\n';
    }
    else{
        cout << "cubelover" << '\n';
    }


    return 0;
}