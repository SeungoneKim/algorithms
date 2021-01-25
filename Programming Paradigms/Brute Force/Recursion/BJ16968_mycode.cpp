#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

string s;

int go(int cur_idx, int len, char last){
    if(cur_idx==len) return 1;

    char start=(s[cur_idx]=='c'?'a':'0');
    char end=(s[cur_idx]=='c'?'z':'9');

    int ans=0;
    for(int i = start;i<=end;i++){
        if(i != last){
            ans += go(cur_idx+1,len,i);
        }
    }
    return ans;
}

int main(){

    cin >> s;
    int len=s.length();

    int answ = go(0,len,' ');

    cout << answ << '\n';

    return 0;
}