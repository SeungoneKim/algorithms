#include <iostream>

using namespace std;

int main(){

    int tc;
    cin >> tc;

    while(tc--){
        int m,n,x,y;
        cin >> m >> n >> x >> y;

        
        x--; y--;
        bool ok =false;
        for(int k=x;k<(n*m);k+=m){
            if(k%n == y){
                cout << k+1 << '\n';
                ok=true;
                break;
            }
        }
        if(!ok){
            cout << -1 << '\n';
        }
    }
    
    return 0;
}