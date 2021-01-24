#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dp[21];
int whichone[21];
int answ;

void solve(int si, int from, int to){
    if(si==0){
        return;
    }
    else{
        answ++;
    }
    int tmp=0;
    for(int k=1;k<=3;k++){
        if(k!=from && k!=to){
            tmp=k;
        }
    }
    solve(si-1,from,tmp);
    cout << from << ' ' << to << '\n';
    solve(si-1,tmp,to);
}

int main(){

    int size;
    cin >> size;

    dp[1]=1;
    for(int k=2;k<=size;k++){
        dp[k] = 2*dp[k-1]+1;
    }

    cout << dp[size] << '\n';
    solve(size,1,3);

    return 0;
}