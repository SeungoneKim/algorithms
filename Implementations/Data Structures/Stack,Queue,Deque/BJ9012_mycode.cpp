#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

stack <int> lstack;
stack <int> rstack;

int main(){
    
    int tn;
    cin >> tn;
    
    while(tn--){
        string set="";
        cin >> set;
        bool checker = false;
        
        for(int k=0;k<set.length();k++){
            if(lstack.size()<rstack.size()){
                cout << "NO" << endl;
                checker = true;
                break;
            }
            if(set[k]=='(')
                lstack.push(1);
            if(set[k]==')')
                rstack.push(1);
        }
        if(checker == false){
            if(lstack.size() == rstack.size())
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        while(!lstack.empty())
            lstack.pop();
        while(!rstack.empty())
            rstack.pop();
        
    }
    return 0;
}