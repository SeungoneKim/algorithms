#include <vector>
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int n;
char a[20];
vector<string> answ;
bool check[10];

bool good(char x, char y, char op){
    if(op=='<'){
        if(x>y) return false;
    }
    if(op=='>'){
        if(x<y) return false;
    }
    return true;
}

void backtrack(int index, string num){
    if(index==n+1){
        answ.push_back(num);
        return;
    }
    for(int i=0;i<=9;i++){
        if(check[i]) continue;
        if(index==0 || good(num[index-1],i+'0',a[index-1])){
            check[i]=true;
            backtrack(index+1,num+to_string(i));
            check[i]=false;
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    backtrack(0,"");
    auto p= minmax_element(answ.begin(),answ.end());
    cout << *p.second << '\n';
    cout << *p.first << '\n';
    return 0;
}