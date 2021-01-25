#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int trials,variations;
bool d[5001][5001];
int a[10];

void go(int i, int j) {
    if (i > trials) {
        return;
    }
    if (d[i][j]) return;
    d[i][j] = true;
    for (int k=0; k<variations; k++) {
        go(i+j+a[k], j+a[k]);
    }
}

int main(){

    int tc;
    cin >> tc;

    while(tc--){
        
        cin >> trials >> variations;
        
        for(int k=0;k<variations;k++){
            cin >> a[k];
        }
        memset(d,false,sizeof(d));    
        go(0,0);
        int answ=-1;
        for(int i=1;i<=trials;i++){
            if(d[trials][i]){
                answ=i;
            }
        }
        cout << answ << '\n';
    }


    return 0;
}