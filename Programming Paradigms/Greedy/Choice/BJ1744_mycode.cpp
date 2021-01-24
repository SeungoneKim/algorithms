#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int> minus;
    vector<int> plus;
    int one=0;
    bool zero=false;

    for(int k=1;k<=n;k++){
        int tmp=0;
        cin >> tmp;
        if(tmp<0) minus.push_back(tmp);
        else if(tmp>1) plus.push_back(tmp);
        else if(tmp==1) one +=1;
        else zero=true;
    }

    if(plus.size()%2==1){
        plus.push_back(1);
    }
    if(minus.size()%2==1){
        minus.push_back(zero==true?0:1);
    }

    sort(minus.begin(),minus.end());
    sort(plus.begin(),plus.end(),greater<int>());
    
    int answ=one;
    for(int k=0;k<plus.size();k+=2){
        answ += plus[k] * plus[k+1];
    }
    for(int k=0;k<minus.size();k+=2){
        answ += minus[k] * minus[k+1];
    }

    cout << answ << '\n';

    return 0;
}