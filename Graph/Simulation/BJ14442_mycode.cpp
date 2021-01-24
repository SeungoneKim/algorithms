#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

struct room{
    int row;
    int col;
    int pass_through_wall;

    room(int r, int c, int ptw) : row(r), col(c), pass_through_wall(ptw)
    {}
};

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

int matrix[1001][1001];
int dist[1001][1001][11];
queue<room>q;

int main(){

    int rownum,colnum,limit_of_wall;
    cin >> rownum >> colnum >> limit_of_wall;

    for(int k=1;k<=rownum;k++){
        for(int t=1;t<=colnum;t++){
            char x;
            cin >> x;
            matrix[k][t]=x-'0';
        }
    }

    for(int k=1;k<=rownum;k++){
        for(int p=1;p<=colnum;p++){
            memset(dist[k][p],-1,sizeof(dist[k][p]));
        }
    }

    dist[1][1][0]=1;
    room* ptr=new room(1,1,0);
    q.push(*ptr);

    while(!q.empty()){
        int curr=q.front().row;
        int curc=q.front().col;
        int curpass= q.front().pass_through_wall;
        q.pop();

        for(int k=0;k<4;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];

            if(matrix[nextr][nextc]==0 && dist[nextr][nextc][curpass]==-1){
                dist[nextr][nextc][curpass]=dist[curr][curc][curpass]+1;
                room*ptr=new room(nextr,nextc,curpass);
                q.push(*ptr);
            }
            if(matrix[nextr][nextc]==1 && curpass< limit_of_wall && dist[nextr][nextc][curpass+1]==-1){
                dist[nextr][nextc][curpass+1]=dist[curr][curc][curpass]+1;
                room*ptr=new room(nextr,nextc,curpass+1);
                q.push(*ptr);
            }
        }
    }
    int answ=100000000;
    for(int k=0;k<=limit_of_wall;k++){
        if(dist[rownum][colnum][k]<answ && dist[rownum][colnum][k]!=-1){
            answ=dist[rownum][colnum][k];
        }
    }
    if(answ==100000000){
        answ=-1;
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
    cout << '\n';
    */
    cout << answ << '\n';

    return 0;
}