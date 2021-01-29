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
    
    for(int k=0;k<n;k++){
        int tmp;
        cin >> tmp;
        answ ^= tmp;    
    }
    if(answ==0){
        cout << "cubelover" << '\n';
    }
    else{
        cout << "koosaga" << '\n';
    }
    
    return 0;
}