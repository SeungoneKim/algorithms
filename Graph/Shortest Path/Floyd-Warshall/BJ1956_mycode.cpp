#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int infinity=1000000000;

int matrix[401][401];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex, edge;
    cin >> vertex >> edge;

    for(int k=1;k<=vertex;k++){
        for(int t=1;t<=vertex;t++){
            matrix[k][t]=infinity;
        }
    }

    for(int k=1;k<=edge;k++){
        int a,b,w;
        cin >> a >> b >> w;

        matrix[a][b]=w;
    }

    for(int k=1;k<=vertex;k++){
        for(int t=1;t<=vertex;t++){
            if(k==t) continue;
            for(int i=1;i<=vertex;i++){
                if(k==i) continue;
                if(t==i) continue;
                if(matrix[t][k]!=infinity && matrix[k][i]!=infinity){
                    if(matrix[t][k]+matrix[k][i]<matrix[t][i]){
                        matrix[t][i]=matrix[t][k] + matrix[k][i];
                    }
                }
            }
        }
    }

    int answ= infinity;
    for(int k=1;k<=vertex;k++){
        for(int t=1;t<=vertex;t++){
            if(k==t) continue;
            if(matrix[k][t]!=infinity && matrix[t][k]!=infinity){
                if(answ>matrix[k][t]+matrix[t][k]){
                    answ = matrix[k][t] + matrix[t][k];
                }
            }
        }
    }
    if(answ==infinity){
        answ=-1;
    }

    cout << answ << '\n';

    return 0;
}