#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

bool check[20*50+1];

int main(){

    int n;
    cin >> n;

    for(int a=0;a<=n;a++){
        for(int b=0;b<=n-a;b++){
            for(int c=0;c<=n-a-b;c++){
                int d= n-a-b-c;
                int tmp= a + b*5 + c*10 + d*50;
                check[tmp]= true;
            }
        }
    }

    int answ=0;
    for(int k=0;k<=1000;k++){
        if(check[k]){
            answ++;
        }
    }

    cout << answ << '\n';

    return 0;
}