#include<iostream>
#include<cstring>
#include<stack>

using namespace std;

stack<char> ls;
stack<char> rs;

int main(){
    //getting input
    string s;
    int an;
    cin >> s >> an;
   
    //pushing the inputs to the left stack
    for(int k=0;k<s.size();k++){
        ls.push(s[k]);
    }
    
    //getting cmds
    while(an--){
        char cmd;
        cin >> cmd;
        
        switch(cmd){
            case 'P':
                char io;
                cin >> io;
                
                ls.push(io);
                break;
            case 'L':
                if(!ls.empty()){
                    char move;
                    move = ls.top();
                    ls.pop();
                    rs.push(move);
                }
                break;
            case 'D':
                if(!rs.empty()){
                    char move;
                    move = rs.top();
                    rs.pop();
                    ls.push(move);
                }
                break;
            case 'B':
                if(!ls.empty()){
                    ls.pop();
                }
                break;
            default:
                break;
        }
    }
    
    //printing out the result using stacks
    while(!ls.empty()){
        char tmp;
        tmp = ls.top();
        rs.push(tmp);
        ls.pop();
    }
    while(!rs.empty()){
        char tmp;
        tmp = rs.top();
        cout << tmp;
        rs.pop();
    }
    
    return 0;
}