#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int rownum,colnum;
    cin >> rownum >> colnum;

    int answ=0;
    if(rownum==1){
        answ=1;
    }
    else if(rownum==2){
        if(colnum>=7){
            answ=4;
        }
        else{ // colnum<7
            answ = (colnum+1)/2;
        }   
    }
    else{ // rownum>=3
        if(colnum>=7){
            answ = colnum-2;
        }
        else{ // colnum<7
            if(colnum>=4){
                answ = 4;
            }
            else{
                answ = colnum;
            }
        }
    }

    cout << answ << '\n';
    
    return 0;
}