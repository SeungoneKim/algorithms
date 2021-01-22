#include <iostream>
#include <algorithm>

using namespace std;

char matrix[51][51];

int dx[2]={1,0};
int dy[2]={0,1};

int check(int size){
    int answ=1;
    
    for(int r=1;r<=size;r++){
        int cnt=1;
        for(int c=1;c<size;c++){
            if(matrix[r][c]==matrix[r][c+1]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(answ<cnt) answ=cnt;
        }
        cnt=1;
        for(int c=1;c<size;c++){
            if(matrix[c][r]==matrix[c+1][r]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(answ<cnt) answ=cnt;
        }
    }
    /*
    for(int r=1;r<size;r++){
        int cnt=1;
        for(int c=1;c<=size;c++){
            if(matrix[r][c]==matrix[r+1][c]){
                cnt++;
            }
            else{
                cnt=1;
            }
            if(answ<cnt) answ=cnt;
        }
    }
    */
    return answ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;

    for(int k=1;k<=size;k++){
        for(int t=1;t<=size;t++){
            cin >> matrix[k][t];
        }
    }

    int answ=0;
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            for(int k=0;k<2;k++){
                if(1<=r+dx[k] && r+dx[k]<=size && 1<=c+dy[k] && c+dy[k]<=size){
                    swap(matrix[r][c],matrix[r+dx[k]][c+dy[k]]);
                    int che=check(size);
                    if(answ<che){
                        answ=che;
                    }
                    swap(matrix[r][c],matrix[r+dx[k]][c+dy[k]]);
                }
            }
        }
    }

    cout << answ << '\n';

    return 0;
}