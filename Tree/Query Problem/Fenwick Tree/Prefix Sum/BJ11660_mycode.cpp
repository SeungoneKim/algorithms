#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int matrix[1025][1025];
long long s[1025][1025];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size,query;
    cin >> size >> query;

    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            cin >> matrix[r][c];
        }
    }
    s[1][1]=matrix[1][1];
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            if(!(r==1 && c==1)){
                s[r][c]=s[r-1][c]+s[r][c-1]-s[r-1][c-1]+matrix[r][c];
            }
        }
    }

    while(query--){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        long long answ=0;
        answ = s[c][d]-s[a-1][d]-s[c][b-1]+s[a-1][b-1];
        cout << answ << '\n';
    }

    return 0;
}