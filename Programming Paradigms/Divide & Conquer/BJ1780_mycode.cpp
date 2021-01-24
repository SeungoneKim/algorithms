#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[3000][3000];
int minusone_num=0;
int plusone_num=0;
int zero_num=0;

void solve(int si,int startr, int startc){
    int standard= matrix[startr][startc];
    bool flg=false;
    for(int r=startr;r<startr+si;r++){
        for(int c=startc;c<startc+si;c++){
            if(matrix[r][c]!=standard){
                flg=true;
            }
        }
    }
    if(!flg){
        // cout << si << ' ' << startr << ' ' << startc << '\n';
        if(standard==-1){
            minusone_num += 1;
        }
        else if(standard==0){
            zero_num += 1;
        }
        else{
            plusone_num += 1;
        }
    }
    else{
        for(int k=0;k<3;k++){
            for(int i=0;i<3;i++){
                solve(si/3,startr+(k*si/3),startc+(i*si/3));
            }
        }
    }
}

int main(){

    int size;
    cin >> size;

    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            cin >> matrix[r][c];
        }
    }

    solve(size,1,1);

    cout << minusone_num << '\n';
    cout << zero_num << '\n';
    cout << plusone_num << '\n';

    return 0;
}