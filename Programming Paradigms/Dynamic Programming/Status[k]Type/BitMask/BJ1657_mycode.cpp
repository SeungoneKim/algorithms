#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <map>

using namespace std;

int infinity=100000000;
int rownum,colnum;
char matrix[14][14];
int dp[196][1<<14];
map<pair<char,char>,int>m;

int go(int target,int state){
    if(target==rownum*colnum && state==0){
        return 0;
    }
    else if(target>=rownum*colnum){
        return -infinity;
    }

    int& answ= dp[target][state];
    if(answ!=-1) return answ;

    int row= target/colnum;
    int col= target%colnum;

    // check if the target is already filled
    if((state&1)>0){
        return answ=go(target+1,(state>>1));
    }
    else{
        // considering not filling target
        answ= go(target+1,(state>>1));

        // filling with 2*1
        if((state&2)==0){
            if(col!=colnum-1){
                answ= max(answ,go(target+2,(state>>2))+m[{matrix[row][col],matrix[row][col+1]}]);
            }
        }
        // filling with 1*2
        if(row!=rownum-1){
            answ= max(answ,go(target+1,(state>>1)|(1<<(colnum-1)))+m[{matrix[row][col],matrix[row+1][col]}]);
        }
    }
    return answ;
}

int main(){

    cin >> rownum >> colnum;

    for(int i=0;i<rownum;i++){
        for(int j=0;j<colnum;j++){
            cin >> matrix[i][j];
        }
    }

    m[{'A','A'}]=10;
    m[{'A','B'}]=8; m[{'B','A'}]=8;
    m[{'A','C'}]=7; m[{'C','A'}]=7;
    m[{'B','B'}]=6;
    m[{'A','D'}]=5; m[{'D','A'}]=5;
    m[{'B','C'}]=4; m[{'C','B'}]=4;
    m[{'B','D'}]=3; m[{'D','B'}]=3;
    m[{'C','C'}]=3;
    m[{'C','D'}]=2; m[{'D','C'}]=2;
    m[{'D','D'}]=2;
    m[{'A','F'}]=1; m[{'B','F'}]=1; m[{'C','F'}]=1; m[{'D','F'}]=1;
    m[{'F','A'}]=1; m[{'F','B'}]=1; m[{'F','C'}]=1; m[{'F','D'}]=1;
    m[{'F','F'}]=0;

    memset(dp,-1,sizeof(dp));
    cout << go(0,0) << '\n';



    return 0;
}