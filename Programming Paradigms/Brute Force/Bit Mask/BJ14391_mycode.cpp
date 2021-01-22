#include <iostream>
#include <algorithm>

using namespace std;

int matrix[4][4];

int main(){

    int rownum, colnum;
    cin >> rownum >> colnum;

    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            char x;
            cin >> x;
            matrix[r][c]=x-'0';
        }
    }

    int answ=0;
    for(int k=0;k<(1<<(rownum*colnum));k++){
        int sum=0;
        for(int t=0;t<rownum;t++){
            int cur=0;
            for(int i=0;i<colnum;i++){
                int idx= t*colnum+i;
                if((k&(1<<idx))==0){
                    cur = cur*10 + matrix[t][i];
                }
                else{
                    sum += cur;
                    cur=0;
                }
            }
            sum += cur;
        }
        for(int i=0;i<colnum;i++){
            int cur=0;
            for(int j=0;j<rownum;j++){
                int idx= j*colnum+i;
                if((k&(1<<idx))!=0){
                    cur = cur*10 + matrix[j][i];
                }
                else{
                    sum += cur;
                    cur=0;
                }
            }
            sum += cur;
        }
        answ = max(answ,sum);
    }

    cout << answ << '\n';

    return 0;
}