#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int matrix[101][101];
int kbnum[101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex,edge;
    cin >> vertex >> edge;

    for(int k=1;k<=edge;k++){
        int a,b;
        cin >> a >> b;

        matrix[a][b]=1;
        matrix[b][a]=1;
    }

    for(int k=1;k<=vertex;k++){
        for(int i=1;i<=vertex;i++){
            for(int t=1;t<=vertex;t++){
                if(matrix[i][k]>0 && matrix[k][t]>0){
                    if(matrix[i][t]==0 || (matrix[i][t]!=0 && matrix[i][t]>matrix[i][k]+matrix[k][t]))
                    matrix[i][t] = matrix[i][k]+matrix[k][t];
                }
            }
        }
    }

    for(int k=1;k<=vertex;k++){
        for(int t=1;t<=vertex;t++){
            kbnum[k] += matrix[k][t];
        }
    }

    int tmp=-1;
    int answ=100000000;
    for(int k=1;k<=vertex;k++){
        if(answ>kbnum[k]){
            answ=kbnum[k];
            tmp=k;
        }
    }

    cout << tmp << '\n';

    return 0;
}