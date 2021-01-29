#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int p[200001][21];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int k=1;k<=n;k++){
        cin >> p[k][0];
    }
    
    for(int k=1;k<=20;k++){
        for(int i=1;i<=n;i++){
            if(p[i][k-1]!=0){
                p[i][k]=p[p[i][k-1]][k-1];
            }
        }
    }

    int query;
    cin >> query;

    while(query--){
        int a,b;
        cin >> a >> b;
        
        for(int i=0;i<=20;i++){
            if(a&(1<<i)){
                b=p[b][i];
            }
        }

        cout << b << '\n';
    }
    
    return 0;
}