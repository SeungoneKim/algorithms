#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int matrix[51][51];
bool can_move[51][51][4]; // 0:down, 1:up, 2:right, 3:left

int matrix_group[51][51];
int howmuch_in_group[2501];

int dr[4]={0,-1,0,1};
int dc[4]={-1,0,1,0};

int colnum,rownum;

int bfs(int initr, int initc, int gn){
    queue<pair<int,int>>q;
    int howmuch=1;
    matrix_group[initr][initc]=gn;
    q.push({initr,initc});

    while(!q.empty()){

        int curr=q.front().first;
        int curc=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(can_move[curr][curc][k]==false){
                    if(matrix_group[nextr][nextc]==0){
                        q.push({nextr,nextc});
                        matrix_group[nextr][nextc]=gn;
                        howmuch++;
                    }
                }
            }
        }
    }
    return howmuch;
}

int main(){

    cin >> colnum >> rownum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
            for(int k=0;k<4;k++){
                if(matrix[r][c] & (1<<k)){
                    can_move[r][c][k]=true;
                }
            }
        }
    }

    int cnt=1;
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(matrix_group[r][c]==0){
                howmuch_in_group[cnt]= bfs(r,c,cnt);
                cnt++;
            }
        }
    }
    cout << cnt-1 << '\n';
    
    int second_answ=0;
    int tmp=0;
    for(int k=1;k<cnt;k++){
        if(howmuch_in_group[k]>second_answ){
            tmp=k;
            second_answ=howmuch_in_group[k];
        }
    }
    cout << second_answ << '\n';

    int third_answ=0;
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            int curr=r;
            int curc=c;
            for(int k=0;k<4;k++){
                int nextr=curr+dr[k];
                int nextc=curc+dc[k];
                if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                    if(matrix_group[curr][curc]!=matrix_group[nextr][nextc]){
                        if(howmuch_in_group[matrix_group[curr][curc]]+howmuch_in_group[matrix_group[nextr][nextc]]>third_answ){
                            third_answ= howmuch_in_group[matrix_group[curr][curc]]+howmuch_in_group[matrix_group[nextr][nextc]];
                        }
                    }
                }
            }
        }
    }
    cout << third_answ << '\n';

    return 0;
}