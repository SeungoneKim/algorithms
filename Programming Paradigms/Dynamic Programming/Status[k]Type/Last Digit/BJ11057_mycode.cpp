#include <iostream>

using namespace std;

int dp[1001][10];

int main(){
    int digitnum;
    cin >> digitnum;
    
    for(int k=0;k<=9;k++){
        dp[1][k] = 1;
    }
    
    for(int k=2;k<=digitnum;k++){ // k is digitnum
        for(int q=0;q<=9;q++){ // q is last number of 'n' digit
            for(int p=0;p<=9;p++){// p is last number of 'n-1' digit
                if(q>=p)
                    dp[k][q] += dp[k-1][p] %10007;
            }
        }
    }
    
    int result=0;
    for(int k=0;k<=9;k++){
        result += dp[digitnum][k] %10007;
    }
    result = result %10007;
    
    cout << result;
    
    return 0;
}