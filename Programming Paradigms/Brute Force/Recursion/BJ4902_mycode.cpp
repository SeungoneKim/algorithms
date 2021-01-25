#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int n, answ;
int a[401][401];
int s[401][401];

void calc(int row, int left, int right, int sum){
    if(row<1 || row>n) return;
    if(left<1 || right>2*row-1) return;
    sum += s[row][right] - s[row][left-1];
    if(sum>answ) answ=sum;
    if(left%2==0){
        calc(row-1,left-2,right,sum);
    }
    else{
        calc(row+1,left,right+2,sum);
    }
}

int main(){

    for(int tc=1;;tc++){
        cin >> n;
        if(n==0) break;
        answ=-100000000;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2*i-1;j++){
                cin >> a[i][j];
                s[i][j] = s[i][j-1]+a[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2*i-1;j++){
                calc(i,j,j,0);
            }
        }
        cout << tc << ". " << answ << '\n';
    }


    return 0;
}