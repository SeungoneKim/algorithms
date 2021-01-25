#include <iostream>
#include <algorithm>

using namespace std;

int am[101][101];
int bm[101][101];
int cm[101][101];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> am[r][c];
        }
    }
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> bm[r][c];
        }
    }

    
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cm[r][c] = am[r][c]+bm[r][c];
        }
    }

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cout << cm[r][c] << ' ';
        }
        cout << '\n';
    }


    return 0;
}