#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int rownum,colnum;
int dp[1<<4][240];
char matrix[5][48];
int infinity=100000000;

bool check(int r,int c){
    return (r+c)%2==0;
}

int go(int state,int target, bool flg){
    if(target==rownum*colnum){
        if(state==0) return 0;
        else return -infinity;
    }   
    if(target>rownum*colnum){
        return -infinity;
    }

    int& answ = dp[state][target];
    if(answ!=-1) return answ;

    int col= target/rownum;
    int row= target%rownum;
    // we first check if the target we are discussing about is appropriate to put a block
    if(matrix[row][col]=='X'){
        if(flg==false)
            return answ = go(state>>1,target+1,false);
        else
            return answ = go((state>>1)|(1<<(rownum-1)),target+1,false);
    }
    // case of not putting any block
    if(flg==false)
        answ = go(state>>1,target+1,false);
    else
        answ = go((state>>1)|(1<<(rownum-1)),target+1,false);
    // we have 4 ways to put a block : we discuss each of them one by one.
    if((state&1)==0){
        // case1
        if(row!=rownum-1 && col!=colnum-1 && check(row+1,col)){
            if(matrix[row+1][col]=='.' && matrix[row+1][col+1]=='.'){
                if((state&2)==0){
                    if(flg==false)
                        answ = max(answ,go((state>>2)|(1<<(rownum-1)),target+2,false)+1);
                    else
                        answ = max(answ,go((state>>2)|(1<<(rownum-1))|(1<<(rownum-2)),target+2,false)+1);
                    cout << 1 << ' ' << row << ' ' << col << ' ' << answ << ' ' << '\n';
                }
            }
        }
        // case2
        if(row!=rownum-1 && col!=colnum-1 && flg==false && check(row,col)){
            if(matrix[row+1][col]=='.' && matrix[row][col+1]=='.'){
                if((state&2)==0){
                    answ = max(answ,go((state>>2)|(1<<(rownum-2)),target+2,false)+1);
                    cout << 2 << ' ' << row << ' ' << col << ' ' << answ << '\n';
                }
            }
        }
        // case3
        if(row!=rownum-1 && col!=colnum-1 && flg==false && check(row,col+1)){
            if(matrix[row][col+1]=='.' && matrix[row+1][col+1]=='.'){
                answ = max(answ,go((state>>1)|(1<<(rownum-1)),target+1,true)+1);
                cout << 3 << ' ' << row << ' ' << col << ' ' << answ << '\n';
            }
        }
        // case4
        if(col!=colnum-1 && flg==false && check(row,col+1)){
            if(matrix[row-1][col+1]=='.' && matrix[row][col+1]=='.'){
                if((state&(1<<(rownum-1)))==0){
                    answ = max(answ,go((state>>1)|(1<<(rownum-1))|(1<<(rownum-2)),target+1,false)+1);
                    cout << 4 << ' ' << row << ' ' << col << ' ' << answ << '\n';
                }
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
    cout << go(0,0,false) << '\n';

    return 0;
}