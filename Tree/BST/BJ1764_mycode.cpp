#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){

    map<string,int>m;

    int a,b;
    cin >> a >> b;
    while(a--){
        string tmp;
        cin >> tmp;
        m[tmp] |= 1;
    }
    while(b--){
        string tmp;
         cin >> tmp;
         m[tmp] |= 2;
    }
    vector<string>v;
    for(auto&a : m){
        if(a.second==3){
            v.push_back(a.first);
        }
    }
    cout << v.size() << '\n';
    for(auto& name : v){
        cout << name << '\n';
    }
    return 0;
}