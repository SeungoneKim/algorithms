#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int rownum,dominonum;
int matrix[1000][3];
int dp[3000][8][1001];
bool check[3000][8][1001];
int infinity=100000000;

int go(int rmo, int state, int leftdomino){
    if(rmo==rownum*3 && state==0 && leftdomino==0){
        return 0;
    }
    else if(rmo>=rownum*3) return -infinity;

    int& answ=dp[rmo][state][leftdomino];
    if(check[rmo][state][leftdomino]) return answ;
    check[rmo][state][leftdomino]=true;
    int row = rmo/3;
    int col = rmo%3;

    // check if this target is already filled.
    if((state&1)>0)
        return answ = go(rmo+1,(state>>1),leftdomino);
    else{
        int tmp=0;
        // we just skip
        tmp = go(rmo+1,(state>>1),leftdomino);
        // case of putting 2*1 block
        if(((state&2)==0) && col!=2 && leftdomino>=1){
            tmp = max(tmp,go(rmo+2,(state>>2),leftdomino-1)+matrix[row][col]+matrix[row][col+1]);
        }
        // case of putting 1*2 block
        if(row!= rownum-1 && leftdomino>=1){
            tmp = max(tmp,go(rmo+1,(state>>1)|4,leftdomino-1)+matrix[row][col]+matrix[row+1][col]);
        }
        answ=tmp;
    }
    return answ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> rownum >> dominonum;

    for(int i=0;i<rownum;i++){
        for(int k=0;k<3;k++){
            cin >> matrix[i][k];
        }
    }

    cout << go(0,0,dominonum) << '\n';

    return 0;
}