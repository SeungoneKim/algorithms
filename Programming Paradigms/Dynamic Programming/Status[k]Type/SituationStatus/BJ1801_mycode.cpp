#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int mak_num;
int mak[17];
int answer=0;
bool dp[71][71][71][71];

int main(){

    cin >> mak_num;

    for(int k=1;k<=mak_num;k++){
        cin >> mak[k];
    }
    memset(dp,false,sizeof(dp));
    dp[0][0][0][0]=true;
    for(int k=1;k<=mak_num;k++){
        for(int l1=0;l1<71;l1++){
            for(int l2=0;l2<71;l2++){
                for(int l3=0;l3<71;l3++){
                    for(int l4=0;l4<71;l4++){
                        if(dp[l1][l2][l3][l4]){
                            if(l1+mak[k]<=70){
                                dp[l1+mak[k]][l2][l3][l4]=true;
                            }
                            if(l2+mak[k]<=70){
                                dp[l1][l2+mak[k]][l3][l4]=true;
                            }
                            if(l3+mak[k]<=70){
                                dp[l1][l2][l3+mak[k]][l4]=true;
                            }
                            if(l4+mak[k]<=70){
                                dp[l1][l2][l3][l4+mak[k]]=true;
                            }
                        }
                    }
                }
            }
        }
    }
    
    for(int i=1;i<=70;i++){
        for(int j=1;j<=70;j++){
            if(dp[i][i][j][j]){
                if(i*j>answer){
                    answer=i*j;
                }
            }
        }
    }
    if(answer==0){
        answer=-1;
    }
    cout << answer << '\n';

    return 0;
}