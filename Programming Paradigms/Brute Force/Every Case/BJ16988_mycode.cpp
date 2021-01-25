#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int rownum,colnum;
int a[21][21];
bool check[21][21];

int bfs(){
    memset(check,false,sizeof(check));
    int answ=0;
    for(int i=0;i<rownum;i++){
        for(int j=0;j<colnum;j++){
            if(a[i][j]==2 && check[i][j]==false){
                bool dead=true;
                queue<pair<int,int>>q;
                q.push({i,j});
                check[i][j]=true;
                int cur=0;
                while(!q.empty()){
                    cur++;
                    int x,y;
                    tie(x,y)= q.front();
                    q.pop();

                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(0<=nx && nx<rownum && 0<=ny && ny<colnum){
                            if(a[nx][ny]==0){
                                dead=false;
                            }
                            else if(a[nx][ny]==2 && check[nx][ny]==false){
                                q.push({nx,ny});
                                check[nx][ny]=true;
                            }
                        }
                    }
                }
                if(dead){
                    answ += cur;
                }
            }
        }
    }
    return answ;
}

int main(){

    cin >> rownum >> colnum;

    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cin >> a[r][c];
        }
    }

    int answ=0;
    for(int x1=0;x1<rownum;x1++){
        for(int y1=0;y1<colnum;y1++){
            if(a[x1][y1]!=0) continue;
            for(int x2=0;x2<rownum;x2++){
                for(int y2=0;y2<colnum;y2++){
                    if(x1==x2 && y1==y2) continue;
                    if(a[x2][y2]!=0) continue;
                    a[x1][y1]=1;
                    a[x2][y2]=1;
                    int cur=bfs();
                    if(answ<cur){
                        answ=cur;
                    }
                    a[x1][y1]=0;
                    a[x2][y2]=0;
                }
            }
        }
    }

    cout << answ << '\n';

    return 0;
}