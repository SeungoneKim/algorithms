#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int dp[10][1<<10];
char matrix[10][10];

bool inside(int state,int target){
    // this is a function to check if the target is assigned to sit inside the state.
    if((state & (1<<target))>0){
        return true;
    }
    return false;
}

bool valid_to_put(int state,int rownum, int rowsize){
    // we first check if there is a seat with x, and if a person was assigned to sit there.
    for(int j=0;j<rowsize;j++){
        if(matrix[rownum][j]=='x' && inside(state,j)){
            return false;
        }
    }

    // we check if there are two people assigned to sit each other sideways.
    for(int j=0;j<rowsize;j++){
        if(inside(state,j)){
            if(j-1>=0 && inside(state,j-1)) return false;
            if(j+1<rowsize && inside(state,j+1)) return false;
        }
    }
    return true;
}

int main(){

    int tc;
    cin >> tc;
    
    while(tc--){
        int rownum,colnum;
        cin >> rownum >> colnum;
        
        for(int r=0;r<rownum;r++){
            for(int c=0;c<colnum;c++){
                cin >> matrix[r][c];
            }
        }

        memset(dp,0,sizeof(dp));
        for(int r=0;r<rownum;r++){
            for(int s=0;s<(1<<colnum);s++){
                if(valid_to_put(s,r,colnum)){
                    if(r>0){
                        for(int ps=0;ps<(1<<colnum);ps++){
                            if(valid_to_put(ps,r-1,colnum)){
                                int cnt=0;
                                bool flg=false;
                                // last thing we have to check is the state between neighboring rows
                                for(int j=0;j<colnum;j++){
                                    if(inside(s,j)){
                                        if(inside(ps,j-1)){
                                            flg=true;
                                            break;
                                        }
                                        if(inside(ps,j+1)){
                                            flg=true;
                                            break;
                                        }
                                        cnt++;
                                    }
                                }
                                if(!flg){
                                    dp[r][s] = max(dp[r][s],dp[r-1][ps]+cnt);
                                }
                            }
                        }
                    }
                    else{
                        int cnt=0;
                        for(int j=0;j<colnum;j++){
                            if(inside(s,j)){
                                cnt++;
                            }
                        }
                        dp[r][s] = max(dp[r][s],cnt);
                    }
                }
            }
        }
        int answ=0;
        for(int j=0;j<(1<<colnum);j++){
            if(dp[rownum-1][j]>answ){
                answ=dp[rownum-1][j];
            }
        }
        cout << answ << '\n';
    }
    return 0;
}