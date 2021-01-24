#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    string s;
    cin >> s;

    sort(s.begin(),s.end(),greater<char>());

    bool is_it_possible=true;
    if(s[s.size()-1]!='0'){
        is_it_possible=false;
    }
    int tmp=0;
    for(int k=0;k<s.size();k++){
        tmp += s[k];
        tmp %=3;
    }
    
    if(tmp %3 !=0){
        is_it_possible=false;
    }

    if(!is_it_possible){
        cout << -1 << '\n';
    }
    else{
        for(int k=0;k<s.size();k++){
            cout << s[k];
        }
        cout << '\n';
    }

    return 0;
}