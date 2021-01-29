#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int matrix[101][101];
int dist[101][101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex;
    cin >> vertex;

    for(int k=1;k<=vertex;k++){
        for(int t=1;t<=vertex;t++){
            cin >> matrix[k][t];
            if(matrix[k][t]==1){
                dist[k][t]=1;
            }
        }
    }

    for(int k=1;k<=vertex;k++){
        for(int i=1;i<=vertex;i++){
            for(int j=1;j<=vertex;j++){
                if(dist[i][k]==1 && dist[k][j]==1){
                    dist[i][j]=1;
                }
            }
        }
    }

    for(int k=1;k<=vertex;k++){
        for(int j=1;j<=vertex;j++){
            cout << dist[k][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}