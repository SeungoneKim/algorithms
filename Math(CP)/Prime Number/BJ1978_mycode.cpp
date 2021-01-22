#include <iostream>

using namespace std;

int arr[101];

bool checkprime(int num){
    if(num<2) return false;

    for(int k=2;k*k<=num;k++){ // sqrt(n)을 사용하지 않음
        if(num%k==0)
            return false;
    }

    return true;
}

int main(){
    int num;
    cin >> num;

    for(int k=1;k<=num;k++){
        cin >> arr[k];
    }

    int answ=0;
    for(int k=1;k<=num;k++){
        if(checkprime(arr[k])) answ++;
    }

    cout << answ << '\n';

    return 0;
}