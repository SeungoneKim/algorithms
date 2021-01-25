#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int main(){

    string s,p;
    cin >> s >> p;
    int standard=stoi(p);

    int answ=-1;
    sort(s.begin(),s.end());

    do{
        string tmp= s;
        int tmpi = stoi(tmp);
        if(s[0]!='0' && tmpi<=standard && answ<tmpi){
            answ=tmpi;
        }

    }while(next_permutation(s.begin(),s.end()));

    cout << answ << '\n';


    return 0;
}