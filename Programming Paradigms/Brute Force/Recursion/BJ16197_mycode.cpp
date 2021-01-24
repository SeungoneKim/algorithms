#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char matrix[22][22];
int rownum, colnum;

int answ=100000;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

void backtrack(int idx, int r1, int c1, int r2, int c2){
    if(idx==11){
        return;
    }
    bool case1=false, case2=false;
    if(!(1<=r1 && r1<=rownum && 1<=c1 && c1<=colnum)){
        case1=true;
    }
    if(!(1<=r2 && r2<=rownum && 1<=c2 && c2<=colnum)){
        case2=true;
    }
    if(case1 && case2){
        return;
    }
    if(case1 || case2){
        if(idx<answ){
            answ = idx;
            // cout << r1 << ' ' << c1 << ' ' << r2 << ' ' << c2 << ' ' << idx << '\n';
        }
        return;
    }

    for(int k=0;k<4;k++){
        int nextr1=r1+dr[k];
        int nextc1=c1+dc[k];
        int nextr2=r2+dr[k];
        int nextc2=c2+dc[k];
        if(matrix[nextr1][nextc1]=='#'){
            nextr1=r1;
            nextc1=c1;
        }
        if(matrix[nextr2][nextc2]=='#'){
            nextr2=r2;
            nextc2=c2;
        }
        backtrack(idx+1,nextr1,nextc1,nextr2,nextc2);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> rownum >> colnum;

    int r1=0,r2=0,c1=0,c2=0;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
            if(matrix[r][c]=='o'){
                if(r1==0 && r2==0){
                    r2=r;
                    c2=c;
                }
                else{
                    r1=r;
                    c1=c;
                }
            }
        }
    }

    backtrack(0,r1,c1,r2,c2);
    if(answ==100000){
        cout << -1 << '\n';
    }
    else{
        cout << answ << '\n';
    }

    return 0;
}