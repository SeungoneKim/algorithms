#include <iostream>
#include <cstring>

using namespace std;

char matrix[51][51];

long long check[51][51];
long long which_search[51][51];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};

bool dfs(int curr,int curc,int which,int cnt,int& rownum,int& colnum){
    check[curr][curc]=cnt;
    which_search[curr][curc]=which;

    for(int k=0;k<4;k++){
        int nextr=curr+dx[k];
        int nextc=curc+dy[k];
        if(1<=nextr&&nextr<=rownum&&1<=nextc&&nextc<=colnum){
            if(matrix[nextr][nextc]==matrix[curr][curc]){
                if(which_search[nextr][nextc]!=which_search[curr][curc]){
                //cout << which << ' ' << curr << ' ' << curc << ' ' << nextr << ' ' << nextc << ' ' << '\n';
                    if(dfs(nextr,nextc,which,cnt+1,rownum,colnum))
                        return true;
                    else
                    {
                        //cout << "out: " << which << ' ' << curr << ' ' << curc << ' ' << nextr << ' ' << nextc << ' ' << '\n';
                    }
                    
                }
                else{
                    if(check[nextr][nextc]+3<=check[curr][curc]){
                        //cout << "answ: " << which << ' ' << curr << ' ' << curc << ' ' << nextr << ' ' << nextc << ' ' << '\n';
                        return true;
                    }
                }
            }
        }
    }
    return false;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
        }
    }
    
    int sc=1;
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            bool flg = dfs(r,c,sc,1,rownum,colnum);
            if(flg==true){
                cout << "Yes" << '\n';
                return 0;
            }
            else{
                sc++;
                for(int k=1;k<=rownum;k++){
                    for(int t=1;t<=colnum;t++){
                        check[k][t]=0;
                    }
                }
            }
        }
    }

    cout << "No" << '\n';
    
    return 0;
}