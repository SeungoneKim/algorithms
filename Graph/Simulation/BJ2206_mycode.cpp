#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct room{
    int row;
    int col;
    bool pass_through_wall;

    room(int r, int c, bool ptw) : row(r), col(c), pass_through_wall(ptw)
    {}
};

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

int matrix[1001][1001];
int dist[1001][1001][2];
queue<room>q;

int main(){

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int k=1;k<=rownum;k++){
        for(int t=1;t<=colnum;t++){
            char x;
            cin >> x;
            matrix[k][t]=x-'0';
        }
    }

    for(int k=1;k<=rownum;k++){
        for(int p=1;p<=colnum;p++){
            dist[k][p][0]=-1;
            dist[k][p][1]=-1;
        }
    }

    dist[1][1][0]=1;
    room* ptr=new room(1,1,false);
    q.push(*ptr);

    while(!q.empty()){
        int curr=q.front().row;
        int curc=q.front().col;
        bool curpass= q.front().pass_through_wall;
        q.pop();

        for(int k=0;k<4;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];

            if(matrix[nextr][nextc]==0 && dist[nextr][nextc][curpass]==-1){
                dist[nextr][nextc][curpass]=dist[curr][curc][curpass]+1;
                room*ptr=new room(nextr,nextc,curpass);
                q.push(*ptr);
            }
            if(matrix[nextr][nextc]==1 && curpass==false && dist[nextr][nextc][1]==-1){
                dist[nextr][nextc][1]=dist[curr][curc][0]+1;
                room*ptr=new room(nextr,nextc,true);
                q.push(*ptr);
            }
        }
    }
    int answ=-1;
    if(dist[rownum][colnum][0]==-1){
        if(dist[rownum][colnum][1]==-1){
            answ=-1;
        }
        else{
            answ=dist[rownum][colnum][1];
        }
    }
    else{
        if(dist[rownum][colnum][1]==-1){
            answ=dist[rownum][colnum][0];
        }
        else{
            answ=min(dist[rownum][colnum][0],dist[rownum][colnum][1]);
        }
    }
    /*
    for(int k=1;k<=rownum;k++){
        for(int t=1;t<=colnum;t++){
            cout << dist[k][t][0] << ' ';
        }
        cout << '\n';
    }
    for(int k=1;k<=rownum;k++){
        for(int t=1;t<=colnum;t++){
            cout << dist[k][t][1] << ' ';
        }
        cout << '\n';
    }
`   */
    cout << answ << '\n';

    return 0;
}