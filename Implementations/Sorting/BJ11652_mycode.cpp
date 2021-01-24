#include <iostream>
#include <algorithm>

using namespace std;

long long numlist[1000000];

int main(){

    int num;
    cin >> num;

    
    for(int k=0;k<num;k++){
        cin >> numlist[k];
    }

    sort(numlist,numlist+num);

    long long answ=numlist[0];
    int answ_num=1;
    int cnt=1;
    for(int k=1;k<num;k++){
        if(numlist[k]==numlist[k-1]){
            cnt++;
        }
        else{
            cnt=1;
        }
        if(cnt>answ_num){
            answ_num=cnt;
            answ=numlist[k];
            
        }
    }

    cout << answ << '\n';

    return 0;
}