#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int dp[51][51][51][51];
int matrix[51][51];
int dr[2]={1,0};
int dc[2]={0,1};

int main(){

    int rownum,colnum,orak_num;
    cin >> rownum >> colnum >> orak_num;

    for(int i=0;i<orak_num;i++){
        int a,b;
        cin >> a >> b;
        matrix[a-1][b-1]=i+1;
    }

    if(matrix[0][0]==0){
        dp[0][0][0][0]=1;
    }
    else{
        dp[0][0][matrix[0][0]][1]=1;
    }
    
    for(int t=0;t<=orak_num;t++){
        for(int r=0;r<rownum;r++){
            for(int c=0;c<colnum;c++){
                for(int k=0;k<2;k++){
                    int nextr=r+dr[k];
                    int nextc=c+dc[k];
                    if(nextr<rownum && nextc<colnum){
                        for(int n=0;n<=t;n++){
                            if(matrix[nextr][nextc]==0){
                                dp[nextr][nextc][t][n] += dp[r][c][t][n];
                            }
                            else{
                                if(matrix[nextr][nextc]>t)
                                    dp[nextr][nextc][t+1][n+1] += dp[r][c][t][n];
                            }
                        }
                    }
                }
            }
        }
    }
    
    
    for(int t=0;t<=orak_num;t++){
        for(int r=0;r<rownum;r++){
            for(int c=0;c<colnum;c++){
                cout << dp[r][c][t] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
        cout << '\n';
    }
    
    for(int k=0;k<=orak_num;k++){
        cout << dp[rownum-1][colnum-1][k] << ' ';
    }
    cout << '\n';

    return 0;    
}
