#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){

    string s;
    cin >> s;

    int tmpnum=0;
    vector<int> numbers;
    vector<int> sign;
    for(int k=0;k<s.size();k++){
        if(s[k]=='+'){
            numbers.push_back(tmpnum);
            tmpnum=0;
            sign.push_back(1);
        }
        else if(s[k]=='-'){
            numbers.push_back(tmpnum);
            tmpnum=0;
            sign.push_back(-1);
        }
        else{
            tmpnum = tmpnum*10 + (s[k]-'0');
        }
    }
    numbers.push_back(tmpnum);

    bool has_minus_arrived = false;
    int answ=numbers[0];
    for(int k=0;k<sign.size();k++){
        if(sign[k]==-1){
            has_minus_arrived=true;
        }
        if(has_minus_arrived){
            answ -= numbers[k+1];
        }
        else{
            answ += numbers[k+1];
        }
    }

    cout << answ << '\n';

    return 0;
}