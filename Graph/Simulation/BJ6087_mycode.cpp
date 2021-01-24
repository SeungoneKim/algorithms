#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

char matrix[101][101];
int dist[101][101];

queue<pair<int,int>>q;

int main(){

    int colnum,rownum;
    cin >> colnum >> rownum;

    int startr=0,startc=0,goalr=0,goalc=0;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
            if(matrix[r][c]=='C'){
                if(startr==0 && startc==0){
                    startr=r;
                    startc=c;
                }
                if(startr!=0 && startc!=0){
                    goalr=r;
                    goalc=c;
                }
            }
        }
    }

    memset(dist,-1,sizeof(dist));

    q.push({startr,startc});
    dist[startr][startc]=0;

    while(!q.empty()){
        int curr=q.front().first;
        int curc=q.front().second;
        int curd=dist[curr][curc];
        q.pop();

        for(int k=0;k<4;k++){
            int idx=1;
            int nextd=curd+1;

            while(1){
                int nextr=curr+dr[k]*idx;
                int nextc=curc+dc[k]*idx;
                if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                    if(matrix[nextr][nextc]=='.' || matrix[nextr][nextc]=='C'){
                        if(dist[nextr][nextc]==-1 || (dist[nextr][nextc]!=-1 && dist[nextr][nextc]>=nextd)){
                            dist[nextr][nextc]=nextd;
                            q.push({nextr,nextc});
                            // cout << curr << ' ' << curc << ' ' << nextr << ' ' << nextc << ' ' << nextd << '\n';
                            idx++;
                        }
                        else{
                            break;
                        }
                    }
                    else{
                        break;
                    }
                }
                else{
                    break;
                }
            }
        }
    }
/*
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cout << dist[r][c] << ' ';
        }
        cout << '\n';
    }
*/
    cout << dist[goalr][goalc]-1 << '\n';

    return 0;
}