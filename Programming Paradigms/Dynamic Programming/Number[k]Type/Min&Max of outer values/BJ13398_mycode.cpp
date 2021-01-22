#include <iostream>

using namespace std;

int untilldp[100001];
int fromdp[100001];
int sequence[100001];

int main(){
    int num;
    cin >> num;

    for(int k=1;k<=num;k++){
        cin >> sequence[k];
    }

    for(int k=1;k<=num;k++){
        fromdp[k]= sequence[k];
        untilldp[k]= sequence[k];
    }

    for(int k=num-1;k>=0;k--){
        fromdp[k] = max(fromdp[k],fromdp[k+1]+sequence[k]);
    }
    for(int k=2;k<=num;k++){
        untilldp[k] = max(untilldp[k],untilldp[k-1]+sequence[k]);
    }
    
    int answ=fromdp[1];
    for(int k=2;k<=num;k++){
        answ = max(answ,fromdp[k]);
    }
    for(int k=1;k<=num;k++){
        answ = max(answ,untilldp[k]);
    }
    for(int k=2;k<num;k++){
        answ = max(answ,untilldp[k-1]+fromdp[k+1]);
    }

    cout << answ << '\n';
    
    return 0;
}