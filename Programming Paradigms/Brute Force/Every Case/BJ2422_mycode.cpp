#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

bool no_mat[201][201];

int main(){

    int n,m;
    cin >> n >> m;

    for(int k=1;k<=m;k++){
        int a,b;
        cin >> a >> b;
        no_mat[a][b]=true;
        no_mat[b][a]=true;
    }

    int answ=0;
    for(int a=1;a<=n;a++){
        for(int b=a+1;b<=n;b++){
            if(no_mat[a][b])continue;
            for(int c=b+1;c<=n;c++){
                if(no_mat[a][c])continue;
                if(no_mat[b][c])continue;
                answ++;
            }
        }
    }

    cout << answ << '\n';

    return 0;
}