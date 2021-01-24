#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> firstteam(20);
int cost[20][20];

int main(){

    int num;
    cin >> num;

    firstteam.resize(num);

    for(int r=0;r<num;r++){
        for(int c=0;c<num;c++){
            cin >> cost[r][c];
        }
    }
    for(int k=0;k<num/2;k++){
        firstteam[k]=1;
    }

    int answ=1000000000;
    do{
        int ft=0;
        int st=0;
        for(int k=0;k<num;k++){
            for(int t=0;t<num;t++){
                if(k==t) continue;
                if(firstteam[k]==1 && firstteam[t]==1){
                    ft += cost[k][t];
                    ft += cost[t][k];
                }
                else if(firstteam[k]==0 && firstteam[t]==0){
                    st += cost[k][t];
                    st += cost[t][k];
                }
            }
        }
        int tmp= abs(ft-st);
        if(tmp<answ){ 
            answ=tmp;
        }
    }while(prev_permutation(firstteam.begin(),firstteam.end()));

    cout << answ/2 << '\n';

    return 0;
}