#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int matrix[21][21];
bool unused[21][21];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size;
    cin >> size;

    
    for(int k=1;k<=size;k++){
        for(int t=1;t<=size;t++){
            cin >> matrix[k][t];        
        }
    }
    

    for(int k=1;k<=size;k++){
        for(int i=1;i<=size;i++){
            if(k==i) continue;
            for(int t=1;t<=size;t++){
                if(k==t) continue;
                if(i==t) continue;
                if(matrix[i][t]>matrix[i][k]+matrix[k][t]){
                    cout << -1 << '\n';
                    return 0;
                }
                if(matrix[i][t]==matrix[i][k]+matrix[k][t]){
                    unused[i][t]=true;
                }
            }
        }
    }

    int answ=0;
    for(int k=1;k<=size;k++){
        for(int t=1;t<=size;t++){
            if(!unused[k][t]){
                answ += matrix[k][t];
            }
        }
    }
    answ /=2;

    cout << answ << '\n';

    return 0;
}