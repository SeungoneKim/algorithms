#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int init_matrix[51][51];
int matrix[51][51];

bool check(int r,int c){
    if(matrix[r][c]!=init_matrix[r][c]){
        return false;
    }
    return true;
}

void change(int r,int c){
    for(int dr=0;dr<3;dr++){
        for(int dc=0;dc<3;dc++){
            if(init_matrix[r+dr][c+dc]==0){
                init_matrix[r+dr][c+dc]=1;
            }
            else{
                init_matrix[r+dr][c+dc]=0;
            }
        }
    }
}

int main(){

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            char x;
            cin >> x;
            init_matrix[r][c]=x-'0';
        }
    }

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            char x;
            cin >> x;
            matrix[r][c]=x-'0';
        }
    }

    int answ=0;
    for(int r=1;r<=rownum-2;r++){
        for(int c=1;c<=colnum-2;c++){
            if(init_matrix[r][c]!=matrix[r][c]){
                change(r,c);
                answ++;
            }
        }
    }

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(!check(r,c)){
                cout << -1 << '\n';
                return 0;
            }
        }
    }

    cout << answ << '\n';
    return 0;
}