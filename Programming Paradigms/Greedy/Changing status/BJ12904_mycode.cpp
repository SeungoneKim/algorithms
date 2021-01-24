#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){

    string start, end;
    cin >> start >> end;

    int s_len= start.length();
    int e_len= end.length();

    bool flg =true;
    if(s_len==e_len){
        flg=false;
    }

    if(flg){
        for(int k=e_len;k>s_len;k--){
            if(end[k-1]=='A'){
                end.pop_back();
            }
            else{
                end.pop_back();
                reverse(end.begin(),end.end());
            }
        }
        if(start != end){
            flg=false;
        }
    }

    if(flg){
        cout << 1 << '\n';
    }
    else{
        cout << 0 << '\n';
    }

    return 0;
}