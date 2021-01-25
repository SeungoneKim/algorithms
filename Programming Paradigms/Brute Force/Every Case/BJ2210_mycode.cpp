#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

int a[5][5];
int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};
set<string> set_s;

void backtrack(int r, int c, int cnt, string s){
    s += to_string(a[r][c]);
    if(cnt==6){
        set_s.insert(s);
        return;
    }
    for(int k=0;k<4;k++){
        int nr=r+dr[k];
        int nc=c+dc[k];
        if(0<=nr && nr<5 && 0<=nc && nc<5){
            backtrack(nr,nc,cnt+1,s);
        }
    }
}

int main(){

    for(int r=0;r<5;r++){
        for(int c=0;c<5;c++){
            cin >> a[r][c];
        }
    }

    for(int r=0;r<5;r++){
        for(int c=0;c<5;c++){
            backtrack(r,c,1,"");
        }
    }

    cout << set_s.size() << '\n';

    return 0;
}