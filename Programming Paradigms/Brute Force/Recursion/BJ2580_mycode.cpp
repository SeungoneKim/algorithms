#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int matrix[9][9];
/*
    we express each square as rownum * 9 + colnum 
    which means it starts from 0 ~ 80
*/
bool rowyes[9][10];
bool colyes[9][10];
bool squareyes[9][10];

bool endflg=false;

void backtrack(int num){

    if(num==81){
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                cout << matrix[r][c] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        endflg=true;
        return;
    }

    int r= num/9;
    int c= num%9;

    if(matrix[r][c]==0){
        for(int k=1;k<=9;k++){
            if(rowyes[r][k]==false && colyes[c][k]==false && squareyes[(r/3)*3+(c/3)][k]==false){
                // cout << r << ' ' << c << ' ' << k << ' ' << num << '\n';
                matrix[r][c]=k;
                rowyes[r][k]=true;
                colyes[c][k]=true;
                squareyes[(r/3)*3+(c/3)][k]=true;
                backtrack(num+1);
                matrix[r][c]=0;
                rowyes[r][k]=false;
                colyes[c][k]=false;
                squareyes[(r/3)*3+(c/3)][k]=false;
                if(endflg){
                    return;
                }
            }
        }
    }
    else{
        backtrack(num+1);
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int r=0;r<9;r++){
        for(int c=0;c<9;c++){
            cin >> matrix[r][c];

            if(matrix[r][c]!=0){
                rowyes[r][matrix[r][c]]=true;
                colyes[c][matrix[r][c]]=true;
                squareyes[(r/3)*3+(c/3)][matrix[r][c]]=true;
            }
        }
    }

    backtrack(0);

    return 0;
}