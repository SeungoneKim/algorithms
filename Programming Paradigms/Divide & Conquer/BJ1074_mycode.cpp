#include <iostream>

using namespace std;

int power2(int k){
    return (1<<k);
}

int solve(int si, int x, int y){
    if(si==1){
        return 2*x+y;
    }
    else{
        if(x< power2(si-1)){
            if(y< power2(si-1)){
                return solve(si-1,x,y);
            }
            else{
                return solve(si-1,x,y-power2(si-1))+power2(2*si-2);
            }
        }
        else{
            if(y< power2(si-1)){
                return solve(si-1,x-power2(si-1),y)+power2(2*si-2)*2;
            }
            else{
                return solve(si-1,x-power2(si-1),y-power2(si-1))+power2(2*si-2)*3;
            }
        }
    }
}

int main(){

    int size;
    cin >> size;

    int targetrow,targetcol;
    cin >> targetrow >> targetcol;

    int answ= solve(size,targetrow,targetcol);

    cout << answ << '\n';

    return 0;
}