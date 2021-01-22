#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

stack <int> s;

int main(){
    string tc;
    cin >> tc;
    
    int answ=0;
    
    for(int k=0;k<tc.size();k++){
        if(tc[k]=='(')
            s.push(k);
        else if(s.top()+1 == k){// case of laser
            s.pop();
            answ +=s.size();
        }
        else{
            s.pop();
            answ +=1;
        }
    }
    
    cout << answ;
    
    return 0;
}

