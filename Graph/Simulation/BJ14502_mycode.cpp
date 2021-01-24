#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int rownum, colnum;
int matrix[10][10];
int tmp_matrix[10][10];

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

queue<pair<int,int>>q;

int bfs(){
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            tmp_matrix[r][c]=matrix[r][c];
            if(tmp_matrix[r][c]==2){
                q.push({r,c});
            }
        }
    }
    while(!q.empty()){
        int curr= q.front().first;
        int curc= q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nextr= curr+dr[k];
            int nextc= curc+dc[k];
            if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(tmp_matrix[nextr][nextc]==0){
                    tmp_matrix[nextr][nextc]=2;
                    q.push({nextr,nextc});
                }
            }
        }
    }
    int cnt=0;
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(tmp_matrix[r][c]==0){
                cnt++;
            }
        }
    }
    return cnt;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
        }
    }

    int answ=0;

    for(int r1=1;r1<=rownum;r1++){
        for(int c1=1;c1<=colnum;c1++){
            if(matrix[r1][c1]==0){
                for(int r2=1;r2<=rownum;r2++){
                    for(int c2=1;c2<=colnum;c2++){
                        if(r2==r1 && c2==c1) continue;
                        if(matrix[r2][c2]==0){
                            for(int r3=1;r3<=rownum;r3++){
                                for(int c3=1;c3<=colnum;c3++){
                                    if(r3==r1 && c3==c1) continue;
                                    if(r3==r2 && c3==c2) continue;
                                    if(matrix[r3][c3]==0){
                                        matrix[r1][c1]=1;
                                        matrix[r2][c2]=1;
                                        matrix[r3][c3]=1;
                                        int tmp=bfs();
                                        if(tmp>answ){
                                            answ=tmp;                                            
                                        }
                                        matrix[r3][c3]=0;
                                        matrix[r2][c2]=0;
                                        matrix[r1][c1]=0;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << answ << '\n';

    return 0;
}