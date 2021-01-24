#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char flip(char x){
    if(x == 'H') return 'T';
    else return 'H';
}

char matrix[20][20];

int main(){

    int num;
    cin >> num;

    for(int k=0;k<num;k++){
        for(int t=0;t<num;t++){
            cin >> matrix[k][t];
        }
    }

    int answ=num*num;
    for(int rs=0;rs<(1<<num);rs++){
        int sum=0;
        for(int j=0;j<num;j++){
            int cnt=0;
            for(int i=0;i<num;i++){
                char cur=matrix[i][j];
                if(rs & (1<<i)){
                    cur = flip(cur);
                }
                if(cur == 'T'){
                    cnt++;
                }
            }
            sum += min(cnt, num-cnt);
        }
        if(answ>sum) answ=sum;
    }
    cout << answ << '\n';
    
    return 0;
}