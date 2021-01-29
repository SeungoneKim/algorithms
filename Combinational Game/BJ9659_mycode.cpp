#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int main(){

    long long n;
    cin >> n;

    if(n%2==0){
        cout << "CY" << '\n';
    }
    else{
        cout << "SK" << '\n';
    }

    return 0;
}