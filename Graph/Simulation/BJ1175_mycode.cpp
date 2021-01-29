#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>
#include <tuple>

using namespace std;

char matrix[51][51];
int dist[51][51][4][4];

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int rownum,colnum;
    cin >> rownum >> colnum;

    int init_r=0,init_c=0;
    int target_r1=0,target_c1=0,target_r2=0,target_c2=0;
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
            if(matrix[r][c]=='S'){
                init_r=r;
                init_c=c;
            }
            if(matrix[r][c]=='C'){
                if(target_r1!=0 && target_c1!=0){
                    target_r2=r;
                    target_c2=c;
                }
                else{
                    target_r1=r;
                    target_c1=c;
                }
            }
        }
    }
    
    memset(dist,-1,sizeof(dist));
    queue<tuple<int,int,int,int>>q;
    for(int k=0;k<4;k++){
        dist[init_r][init_c][k][0]=0;
        q.push(make_tuple(init_r,init_c,k,0));
    }

    int answ=-1;
    while(!q.empty()){
        int curr,curc,dir,s;
        tie(curr,curc,dir,s)=q.front();
        q.pop();
        if(s==3){
            answ=dist[curr][curc][dir][s];
            break;
        }
        for(int k=0;k<4;k++){
            if(dir==k) continue;
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(matrix[nextr][nextc]!='#'){
                    int ns=s;
                    if(matrix[nextr][nextc]=='C'){
                        if(nextr==target_r1 && nextc==target_c1){
                            ns |=1;
                        }
                        else{
                            ns |=2;
                        }
                    }
                    if(dist[nextr][nextc][k][ns]==-1){
                        dist[nextr][nextc][k][ns] = dist[curr][curc][dir][s]+1;
                        q.push(make_tuple(nextr,nextc,k,ns));
                    }
                }
            }
        }
    }
    cout << answ << '\n';

    return 0;
}