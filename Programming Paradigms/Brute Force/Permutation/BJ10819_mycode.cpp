#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int>permu(10001);
vector<int>calcu(10000);

int main(){

    int n;
    cin >> n;

    permu.resize(n);
    calcu.resize(n-1);
    for(int k=0;k<n;k++){
        cin >> permu[k];
    }
    sort(permu.begin(),permu.end());

    int answ=0;
    do{
        for(int k=1;k<n;k++){
            int tmp= permu[k]-permu[k-1];
            if(tmp<0) tmp = -tmp;
            calcu[k-1]=tmp;
        }
        int total=0;
        for(int k=0;k<n-1;k++){
            total += calcu[k];
        }
        if(answ<total) answ=total;
        
    }while(next_permutation(permu.begin(),permu.end()));

    cout << answ << '\n';
    
    return 0;
}