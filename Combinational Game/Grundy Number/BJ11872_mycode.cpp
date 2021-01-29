#include <iostream>
#include <vector>
#include <algorithm>
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
        if(tmp%4==1)
            answ ^= tmp;
        else if(tmp%4==2)
            answ ^= tmp;
        else if(tmp%4==3)
            answ ^= tmp+1;
        else
            answ ^= tmp-1;
    }

    if(answ!=0){
        cout << "koosaga" << '\n';
    }
    else{
        cout << "cubelover" << '\n';
    }

    

    return 0;
}