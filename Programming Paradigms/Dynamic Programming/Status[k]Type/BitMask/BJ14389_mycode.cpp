#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

int rownum,colnum;
char matrix[11][26];
int dp[1<<10][260];
int infinity=100000000;

int go(int state,int target){
    if(target==rownum*colnum){
        if(state==0)return 0;
        else return -infinity;
    }
    if(target>rownum*colnum){
        return -infinity;
    }

    int& answ=dp[state][target];
    if(answ!=-1) return answ;

    int col= target/rownum;
    int row= target%rownum;

    // we first check if the target is filled by matrix
    if(matrix[row][col]=='1'){
        return answ = go(state>>1,target+1)+1;
    }
    // case of not putting any block.
    answ = go(state>>1,target+1);

    // we next check if the target was already filled by blocks.
    if((state&1)==0){    
        // we consider putting 1*1 on the target
        answ = max(answ,go(state>>1,target+1)+1);

        // we next consider putting 2*2 on the target
        if(row!=rownum-1 && col!=colnum-1){
            if( ((state&1)==0) && ((state&2)==0) && matrix[row][col]!='1' && matrix[row+1][col]!='1' && matrix[row][col+1]!='1' && matrix[row+1][col+1]!='1'){
                answ = max(answ,go((state>>2) | (1<<(rownum-1)) | (1<<(rownum-2)), target+2)+16);
            }
        }
        
    }
    return answ;
}

int main(){

    cin >> rownum >> colnum;

    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cin >> matrix[r][c];
        }
    }

    memset(dp,-1,sizeof(dp));
    
    cout << go(0,0) << '\n';

    return 0;
}