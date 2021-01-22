#include <iostream>

using namespace std;

int main(){
    int num;
    cin >> num;
    
    bool flg = false;

    if(num==1){
        return 0;
    }

    for(int k=2;k*k<=num;k++){
        while(num%k==0){
            flg = true;
            cout << k << '\n';
            num /=k;
        }
    }
    if(flg==true){
        if(num!=1)
            cout << num << '\n';
    }
    

    if(flg==false && num != 1){
        cout << num << '\n';
    }

    return 0;
}