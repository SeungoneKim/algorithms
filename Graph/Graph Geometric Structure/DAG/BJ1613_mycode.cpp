#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

// About [a][b], if a is in front of b : 1
//                  a is behind of b : -1
//                  we do not know : 0
int check[401][401];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex,edge;
    cin >> vertex >> edge;

    for(int k=1;k<=edge;k++){
        int a,b;
        cin >> a >> b;
        check[a][b]=1;
        check[b][a]=-1;
    }

    for(int k=1;k<=vertex;k++){
        for(int i=1;i<=vertex;i++){
            if(k==i) continue;
            for(int t=1;t<=vertex;t++){
                if(k==t) continue;
                if(i==t) continue;
                if(check[i][k]==1 && check[k][t]==1){
                    check[i][t]=1;
                }
                if(check[i][k]==-1 && check[k][t]==-1){
                    check[i][t]=-1;
                }
            }
        }
    }

    int query;
    cin >> query;
    for(int k=1;k<=query;k++){
        int a,b;
        cin >> a >> b;
        cout << -check[a][b] << '\n';
    }

    return 0;
}