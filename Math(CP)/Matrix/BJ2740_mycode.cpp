#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int am[101][101];
int bm[101][101];
int cm[101][101];

int main(){

    int a,b;
    cin >> a >> b;
    for(int r=1;r<=a;r++){
        for(int c=1;c<=b;c++){
            cin >> am[r][c];
        }
    }

    int trash,d;
    cin >> trash >> d;
    for(int r=1;r<=b;r++){
        for(int c=1;c<=d;c++){
            cin >> bm[r][c];
        }
    }

    for(int i=1;i<=a;i++){
        for(int j=1;j<=d;j++){
            cm[i][j]=0;
            for(int k=1;k<=b;k++){
                cm[i][j] += am[i][k]*bm[k][j];
            }
        }
    }

    for(int r=1;r<=a;r++){
        for(int c=1;c<=d;c++){
            cout << cm[r][c] << ' ';
        }
        cout << '\n';
    }


    return 0;
}