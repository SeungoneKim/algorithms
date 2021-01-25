#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int matrix[22][22];
int dp[22][22][22][22][22];

int dr[8]={1,1,0,-1,-1,-1,0,1};
int dc[8]={0,-1,-1,-1,0,1,1,1};

int main(){

    int size_mat,len;
    cin >> size_mat >> len;

    for(int r=1;r<=size_mat;r++){
        for(int c=1;c<=size_mat;c++){
            cin >> matrix[r][c];
        }
    }
    
    int answ=0;
    for(int r=1;r<=size_mat;r++){
        for(int c=1;c<=size_mat;c++){
            dp[1][r][c][r][c]=1;
        }
    }

    for(int r=1;r<=size_mat;r++){
        for(int c=1;c<=size_mat;c++){
            for(int x=r-1;x<=r+1;x++){
                for(int y=c-1;y<=c+1;y++){
                    if(1<=x && x<=size_mat && 1<=y && y<=size_mat){
                        if(!(r==x && c==y)){
                            if(matrix[r][c]==matrix[x][y]){
                                dp[2][r][c][x][y]=1;
                            }
                        }
                    }
                }
            }
        }
    }

    for(int k=3;k<=len;k++){
        for(int r=1;r<=size_mat;r++){
            for(int c=1;c<=size_mat;c++){
                for(int x=1;x<=size_mat;x++){
                    for(int y=1;y<=size_mat;y++){
                        if(matrix[r][c]==matrix[x][y]){
                            for(int p=0;p<8;p++){
                                if(1<=r+dr[p] && r+dr[p]<=size_mat && 1<=c+dc[p] && c+dc[p]<=size_mat){
                                    for(int t=0;t<8;t++){
                                        if(1<=x+dr[t] && x+dr[t]<=size_mat && 1<=y+dc[t] && y+dc[t]<=size_mat){
                                            dp[k][r][c][x][y] += dp[k-2][r+dr[p]][c+dc[p]][x+dr[t]][y+dc[t]];
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    
    for(int r=1;r<=size_mat;r++){
        for(int c=1;c<=size_mat;c++){
            for(int x=1;x<=size_mat;x++){
                for(int y=1;y<=size_mat;y++){
                    answ +=dp[len][r][c][x][y];
                }
            }
        }
    }
    

    cout << answ << '\n';
    
    return 0;
}