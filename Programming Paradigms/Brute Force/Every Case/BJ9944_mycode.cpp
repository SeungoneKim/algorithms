#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

char a[30][30];
int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};
int rownum, colnum;

bool ok(int x, int y){
    return 0<=x && x<rownum && 0<=y && y<colnum;
}

int go(int r, int c, int cnt){
    int answ=-1;
    if(cnt==0){
        return 0;
    }
    for(int k=0;k<4;k++){
        int nr=r+dr[k];
        int nc=c+dc[k];
        while(ok(nr,nc) && a[nr][nc]=='.'){
            a[nr][nc]='#';
            cnt--;
            nr += dr[k];
            nc += dc[k];
        }
        nr -= dr[k];
        nc -= dc[k];
        if(!(r==nr && c==nc)){
            int temp=go(nr,nc,cnt);
            if(temp != -1){
                if(answ ==-1 || answ > temp+1){
                    answ=temp+1;
                }
            }
        }
        while(!(r==nr && c==nc)){
            a[nr][nc]='.';
            cnt++;
            nr -= dr[k];
            nc -= dc[k];
        }
    }
    return answ;
}

int main(){
    int tc=1;
    while(cin >> rownum >> colnum){

        int cnt=0;
        for(int r=0;r<rownum;r++){
            for(int c=0;c<colnum;c++){
                cin >> a[r][c];
                if(a[r][c]=='.'){
                    cnt++;
                }
            }
        }

        int answ=-1;
        for(int r=0;r<rownum;r++){
            for(int c=0;c<colnum;c++){
                if(a[r][c]=='.'){
                    a[r][c]='#';
                    int temp = go(r,c,cnt-1);
                    
                    if(temp!=-1){
                        if(answ==-1 || answ>temp){
                            answ=temp;
                        }
                    }

                    a[r][c]='.';
                }
            }
        }
        cout << "Case " << tc << ": " << answ << '\n';
        tc++;
    }
    
    return 0;
}