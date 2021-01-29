#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

int n;
double matrix[21][21];
double dp[1<<20];
bool check[1<<20];

double go(int ord, int s){
    if(ord==n){
        return 1.0;
    }
    if(check[s]){
        return dp[s];
    }
    check[s]=true;
    double& answ=dp[s];
    
    for(int i=0;i<n;i++){
        if((s&(1<<i))==0){
            double tmp = go(ord+1,s|(1<<i))*matrix[ord][i];
            if(answ<tmp){
                answ=tmp;
            }
        }
    }
    return answ;
}

int main(){

    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> matrix[i][j];
            matrix[i][j] /= 100.0;
        }
    }
    
    // dynamic programming : we assume that we assign each person by ascending number.
    
    cout << fixed << setprecision(10) << go(0,0)*100.0 << '\n';

    return 0;
}