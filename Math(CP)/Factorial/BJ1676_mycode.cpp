#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;

    int answ=0;
    int divide =5;
    while(true){
        if(num>=divide){
            answ += num/divide;
            divide *= 5;
        }
        else{
            break;
        }
    }

    cout << answ << '\n';

    return 0;
}