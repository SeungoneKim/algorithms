#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int check[20*100000+1];

int main(){

    int n;
    cin >> n;

    vector<int>numbers(n);
    for(int k=0;k<n;k++){
        cin >> numbers[k];
    }

    for(int k=0;k<(1<<n);k++){
        int sum=0;
        for(int t=0;t<n;t++){
            if(k&(1<<t)){
                sum += numbers[t];
            }
        }
        check[sum]=true;
    }

    for(int t=0;t<20*100000+1;t++){
        if(check[t]==false){
            cout << t << '\n';
            break;
        }
    }

    return 0;
}