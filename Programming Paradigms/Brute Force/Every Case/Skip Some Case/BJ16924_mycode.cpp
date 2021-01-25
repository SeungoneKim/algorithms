#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <tuple>

using namespace std;

char a[101][101];
bool check[101][101];
vector<tuple<int,int,int>>answ;

int main(){

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> a[r][c];
        }
    }

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(a[r][c]=='*'){
                int l=0;
                for(int k=1;;k++){
                    if(r-k>=1 && r+k<=rownum && c-k>=1 && c+k<=colnum){
                        if(a[r-k][c]=='*' && a[r+k][c]=='*' && a[r][c-k]=='*' && a[r][c+k]=='*'){
                            l=k;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                if(l>0){
                    answ.push_back(make_tuple(r,c,l));
                    check[r][c]=true;
                    for(int k=1;k<=l;k++){
                        check[r+k][c]=true;
                        check[r-k][c]=true;
                        check[r][c+k]=true;
                        check[r][c-k]=true;
                    }
                }
            }
        }
    }

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(a[r][c]=='*' && check[r][c]==false){
                cout << -1 << '\n';
                return 0;
            }
        }
    }
    cout << answ.size() << '\n';
    for(int k=0;k<answ.size();k++){
        cout << get<0>(answ[k]) << ' ' << get<1>(answ[k]) << ' ' << get<2>(answ[k]) << '\n';
    }

    return 0;
}