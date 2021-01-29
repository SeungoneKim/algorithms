#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

bool matrix[101][101];
bool check[101][101];

int main(){

    int size;
    cin >> size;

    for(int k=1;k<=size;k++){
        for(int t=1;t<=size;t++){
            char x;
            cin >> x;
            if(x=='Y'){
                matrix[k][t]=true;
            }
        }
    }

    for(int k=1;k<=size;k++){
        for(int t=1;t<=size;t++){
            if(matrix[k][t]==true && matrix[t][k]==false){
                check[k][t]=true;
            }
        }
    }


    for(int k=1;k<=size;k++){
        for(int t=1;t<=size;t++){
            for(int i=1;i<=size;i++){
                if(check[t][k] && check[k][i]){
                    
                        check[t][i]=true;
                    
                }
            } 
        }
    }

    for(int k=1;k<=size;k++){
        if(check[k][k]){
            cout << "NO" << '\n';
            return 0;
        }
    }
    cout << "YES" << '\n';

    return 0;
}