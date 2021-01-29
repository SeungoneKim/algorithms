#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>

using namespace std;

int d[3001][3001];

int main(){

    memset(d,-1,sizeof(d));
    for(int x=0;x<10;x++){
        for(int y=0;y<10;y++){
            if(d[x][y]==-1){
                if(x==0 && y==0){
                    d[x][y]=0;
                }
                else{
                    set<int>s;
                    for(int r=0;r<x;r++){
                        if(d[r][y]!=-1)
                            s.insert(d[r][y]);
                    }
                    for(int c=0;c<y;c++){
                        if(d[x][c]!=-1)
                            s.insert(d[x][c]);
                    }
                    if(x>=1 && y>=1){
                        if(d[x-1][y-1]!=-1)
                            s.insert(d[x-1][y-1]);
                    }
                    int tmp=0;
                    for(int k=0;;k++){
                        if(s.count(k)==0){
                            tmp=k;
                            break;
                        }
                    }
                    d[x][y]=tmp;
                }
            }
        }
    }

    int n;
    cin >> n;
    int answ=0;
    while(n--){
        int a,b;
        cin >> a >> b;
        answ ^= d[a][b];
    }
    if(answ!=0){
        cout << "koosaga" << '\n';
    }
    else{
        cout << "cubelover" << '\n';
    }


    return 0;
}