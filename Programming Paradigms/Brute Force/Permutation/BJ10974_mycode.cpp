#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>permu(10001);

int main(){

    int n;
    cin >> n;

    permu.resize(n);
    for(int k=0;k<n;k++){
        permu[k]=k+1;
    }

    do{

        for(int k=0;k<n;k++){
            cout << permu[k];
            if(k<n-1){
                cout << ' ';
            }
        }
        cout << '\n';
    }while(next_permutation(permu.begin(),permu.end()));
    
    return 0;
}