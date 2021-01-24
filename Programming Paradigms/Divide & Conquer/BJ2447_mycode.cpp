#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool matrix[6600][6600];

void solve(int si,int r,int c){
    if(si==3){
        matrix[r+1][c+1]=true;
        return;
    }
    for(int k=r+(si/3);k<r+(si*2/3);k++){
        for(int t=c+(si/3);t<c+(si*2/3);t++){
            matrix[k][t]=true;
        }
    }
    for(int k=0;k<3;k++){
        for(int t=0;t<3;t++){
            if(k!=1 || t!=1){
                solve(si/3,r+(si*k/3),c+(si*t/3));
            }
        }
    }
}

int main(){

    int size;
    cin >> size;

    solve(size,1,1);

    for(int k=1;k<=size;k++){
        for(int t=1;t<=size;t++){
            if(!matrix[k][t]){
                cout << '*';
            }
            else{
                cout << ' ';
            }
        }
        cout << '\n';
    }


    return 0;
}