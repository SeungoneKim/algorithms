#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

char matrix[101][101];

bool visited_blue[101][101];
bool visited_notblue[101][101];
bool visited_red[101][101];
bool visited_green[101][101];

int size;

int blue;
int notblue;
int red;
int green;

void dfsblue(int row, int col){
    visited_blue[row][col]=true;

    for(int k=0;k<4;k++){
        int nr=row+dr[k];
        int nc=col+dc[k];
        if(1<=nc && nc<=size && 1<=nr && nr<=size){
            if(!visited_blue[nr][nc] && matrix[nr][nc]=='B'){
                dfsblue(nr,nc);
            }
        }
    }
}

void dfsnotblue(int row, int col){
    visited_notblue[row][col]=true;

    for(int k=0;k<4;k++){
        int nr=row+dr[k];
        int nc=col+dc[k];
        if(1<=nc && nc<=size && 1<=nr && nr<=size){
            if(!visited_notblue[nr][nc] && matrix[nr][nc]!='B'){
                dfsnotblue(nr,nc);
            }
        }
    }
}

void dfsred(int row, int col){
    visited_red[row][col]=true;

    for(int k=0;k<4;k++){
        int nr=row+dr[k];
        int nc=col+dc[k];
        if(1<=nc && nc<=size && 1<=nr && nr<=size){
            if(!visited_red[nr][nc] && matrix[nr][nc]=='R'){
                dfsred(nr,nc);
            }
        }
    }
}

void dfsgreen(int row, int col){
    visited_green[row][col]=true;

    for(int k=0;k<4;k++){
        int nr=row+dr[k];
        int nc=col+dc[k];
        if(1<=nc && nc<=size && 1<=nr && nr<=size){
            if(!visited_green[nr][nc] && matrix[nr][nc]=='G'){
                dfsgreen(nr,nc);
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> size;

    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            cin >> matrix[r][c];
        }
    }

    // find blue
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            if(!visited_blue[r][c] && matrix[r][c]=='B'){
                dfsblue(r,c);
                blue++;
            }
        }
    }
    // find not blue
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            if(!visited_notblue[r][c] && matrix[r][c]!='B'){
                dfsnotblue(r,c);
                notblue++;
            }
        }
    }
    // find red
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            if(!visited_red[r][c] && matrix[r][c]=='R'){
                dfsred(r,c);
                red++;
            }
        }
    }
    // find green
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            if(!visited_green[r][c] && matrix[r][c]=='G'){
                dfsgreen(r,c);
                green++;
            }
        }
    }

    cout << red+green+blue << ' ' << notblue+blue << '\n';

    return 0;
}