#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

char matrix[21][21];
int dp[21][21];
int infinity=100000000;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex,edge;
    cin >> vertex >> edge;

    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            matrix[i][j]='0';
            dp[i][j]=infinity;
        }
        dp[i][i]=0;
    }
    for(int k=1;k<=edge;k++){
        int a,b;
        char c;
        cin >> a >> b >> c;
        matrix[a][b]=c;
        matrix[b][a]=c;
        dp[a][b]=1;
        dp[b][a]=1;
    }

    for(int k=1;k<=vertex;k++){
        for(int r=0;r<vertex;r++){
            for(int c=0;c<vertex;c++){
                for(int x=0;x<vertex;x++){
                    for(int y=0;y<vertex;y++){
                        if(!(r==x && c==y)){
                            if(dp[x][y]!=infinity && matrix[r][x]!='0' && matrix[y][c]!='0'){
                                if(matrix[r][x]==matrix[y][c]){
                                    dp[r][c]=min(dp[r][c],dp[x][y]+2);
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if(dp[0][1]>=infinity){
        cout << -1 << '\n';
        return 0;
    }
    cout << dp[0][1] << '\n';


    return 0;
}