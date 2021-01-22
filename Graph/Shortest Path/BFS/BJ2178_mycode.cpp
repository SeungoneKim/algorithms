#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

int matrix[101][101];
int check[101][101];

int dx[4]= {1,-1,0,0};
int dy[4]= {0,0,1,-1};
int infin=10000000;

void bfs(int initr, int initc, int cnt,int rownum, int colnum){
    queue<pair<int,int>> q;
    q.push(make_pair(initr,initc));
    check[initr][initc]=cnt;

    while(!q.empty()){
        
        int curr = q.front().first;
        int curc = q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nextr=curr+dx[k];
            int nextc=curc+dy[k];
            if(1<=nextr&&nextr<=rownum&&1<=nextc&&nextc<=colnum){
                if(matrix[nextr][nextc]==1&&check[nextr][nextc]>check[curr][curc]+1){
                    check[nextr][nextc]=check[curr][curc]+1;
                    q.push(make_pair(nextr,nextc));
                }
            }
        }

    }
}

int main(){

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            scanf("%1d",&matrix[r][c]);
        }
    }

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(matrix[r][c]==1){
                check[r][c]=infin;
            }
        }
    }
    bfs(1,1,1,rownum,colnum);

    cout << check[rownum][colnum] << '\n';

    return 0;
}