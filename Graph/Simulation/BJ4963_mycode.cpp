#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int matrix[51][51];
int check[51][51];
int cnt=1;

int dx[8]={1,-1,0,0,1,1,-1,-1};
int dy[8]={0,0,1,-1,1,-1,1,-1};

void bfs(int initr, int initc, int cnt,int rownum,int colnum){
    queue<pair<int,int>>q;
    q.push(make_pair(initr,initc));
    check[initr][initc]=cnt;
    while(!q.empty()){
        int curr = q.front().first;
        int curc = q.front().second;
        q.pop();
        for(int k=0;k<8;k++){
            int nextr=curr+dx[k];
            int nextc=curc+dy[k];
            if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(check[nextr][nextc]==0 && matrix[nextr][nextc]==1){
                    q.push(make_pair(nextr,nextc));
                    check[nextr][nextc]=cnt;
                }
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int rownum,colnum;
    while(cin>>colnum>>rownum){

        if(rownum==0 && colnum==0){
            return 0;
        }

        for(int r=1;r<=rownum;r++){
            for(int c=1;c<=colnum;c++){
                cin >> matrix[r][c];
            }
        }

        for(int r=1;r<=rownum;r++){
            for(int c=1;c<=colnum;c++){
                if(check[r][c]==0 && matrix[r][c]==1){
                    bfs(r,c,cnt,rownum,colnum);
                    cnt++;
                }
            }
        }
        cout << cnt-1 << '\n';

        memset(check,0,sizeof(check));
        memset(matrix,0,sizeof(matrix));
        cnt=1;
    }

    return 0;
}