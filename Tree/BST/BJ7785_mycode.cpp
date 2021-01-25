#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){

    int n;
    cin >> n;

    set<string>s;
    set<string>::iterator it;
    while(n--){
        string tmp, order;
        cin >> tmp >> order;
        if(order=="enter"){
            s.insert(tmp);
        }   
        else{
            it = s.find(tmp);
            if(it != s.end()){
                s.erase(it);
            }
        }
    }

    for (auto iter = s.rbegin(); iter!=s.rend(); iter++) {
        cout << *iter << '\n';
    }

    return 0;
}