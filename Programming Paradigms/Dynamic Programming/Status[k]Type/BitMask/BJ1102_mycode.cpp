#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int infinity=100000000;
int matrix[16][16];
int dp[16][1<<16];
bool check[16]; // false: off, true: on

int checkstatus(){
    int answ=0;
    for(int i=0;i<n;i++){
        if(check[i]==true){
            answ |= (1<<i);
        }
    }
    return answ;
}

int main(){

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
        }
    }
    int num=0;
    for(int i=0;i<n;i++){
        char x;
        cin >> x;
        if(x=='Y'){
            num++;
            check[i]=true;
        }
    }

    int p;
    cin >> p;

    if(p<num || (num==0 && p!=0)){
        cout << 0 << '\n';
        return 0;
    }
    int init = checkstatus();
    
    for(int i=num;i<=p;i++){
        for(int t=0;t<(1<<n);t++){
            dp[i][t]=infinity;
        }
    }

    dp[num][init]=0;
    for(int k=num+1;k<=p;k++){
        for(int t=0;t<(1<<n);t++){
            if(dp[k-1][t]!=infinity){
                //u->j
                for(int j=0;j<n;j++){
                    if(((1<<j)&t)==0){
                        for(int u=0;u<n;u++){
                            if(j==u) continue;
                            if(((1<<u)&t)>0){
                                if(dp[k][t|(1<<j)]>dp[k-1][t]+matrix[u][j]){
                                    dp[k][t|(1<<j)]=dp[k-1][t]+matrix[u][j];
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    int answ=100000000;
    for(int i=0;i<(1<<n);i++){
        if(dp[p][i]<answ){
            answ=dp[p][i];
        }
    }
    if(answ==100000000){
        answ=-1;
    }

    cout << answ << '\n';

    return 0;
}