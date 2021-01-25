#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int dr[8]={1,1,1,0,0,-1,-1,-1};
int dc[8]={1,0,-1,1,-1,1,0,-1};

int matrix[51][51];
int dist[51][51];

queue<tuple<int,int,int>>q; // {row,col,dist}

int infinity=100000000;

int main(){

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];

            dist[r][c]=infinity;

            if(matrix[r][c]==1){
                q.push(make_tuple(r,c,0));
                dist[r][c]=0;
            }
        }
    }

    while(!q.empty()){
        int curr= get<0>(q.front());
        int curc= get<1>(q.front());
        int curd= get<2>(q.front());
        q.pop();

        for(int k=0;k<8;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            int nextd=curd+1;
            if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(matrix[nextr][nextc]==0){
                    if(dist[nextr][nextc]>nextd){
                        dist[nextr][nextc]=nextd;
                        q.push(make_tuple(nextr,nextc,nextd));
                    }
                }
            }
        }
    }

    int answ=0;
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(dist[r][c]>answ){
                answ=dist[r][c];
            }
        }
    }

    cout << answ << '\n';
    
    return 0;
}