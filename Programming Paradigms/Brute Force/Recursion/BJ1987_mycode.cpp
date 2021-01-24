#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

char matrix[21][21];
bool used[26];
int answ=1;
int rownum, colnum;

void backtrack(int r,int c,int a){
    if(a>answ) answ=a;

    for(int k=0;k<4;k++){
        int nextr=r+dr[k];
        int nextc=c+dc[k];

        if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
            if(used[matrix[nextr][nextc]-'A']==false){
                used[matrix[nextr][nextc]-'A']=true;
                backtrack(nextr,nextc,a+1);
                used[matrix[nextr][nextc]-'A']=false;
            }
        }
    }
}

int main(){

    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
        }
    }

    used[matrix[1][1]-'A']=true;
    backtrack(1,1,1);
    
    cout << answ << '\n';

    return 0;
}