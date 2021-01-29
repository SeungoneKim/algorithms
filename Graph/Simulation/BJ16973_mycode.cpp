#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

using namespace std;

int matrix[1001][1001];
int dist[1001][1001];
int matrixsum[1001][1001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
        }
    }
    matrixsum[1][1]=matrix[1][1];
    for(int r=2;r<=rownum;r++){
        matrixsum[r][1]= matrixsum[r-1][1] + matrix[r][1];
    }
    for(int c=2;c<=colnum;c++){
        matrixsum[1][c]= matrixsum[1][c-1] + matrix[1][c];
    }
    for(int r=2;r<=rownum;r++){
        for(int c=2;c<=colnum;c++){
            matrixsum[r][c]= matrixsum[r-1][c]+matrixsum[r][c-1]-matrixsum[r-1][c-1]+matrix[r][c];
        }
    }

    int square_rownum,square_colnum,init_r,init_c,target_r,target_c;
    cin >> square_rownum >> square_colnum >> init_r >> init_c >> target_r >> target_c;

    memset(dist,-1,sizeof(dist));

    queue<pair<int,int>>q;
    q.push({init_r,init_c});
    dist[init_r][init_c]=0;

    while(!q.empty()){
        int curr=q.front().first;
        int curc=q.front().second;
        q.pop();

        bool tmpflg=false;
        for(int k=0;k<4;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(dist[nextr][nextc]==-1){
                    bool flg=true;
                    switch(k){
                        case 0:
                            if(curr+square_rownum<=rownum){
                                if(matrixsum[curr+square_rownum][curc+square_colnum]-matrixsum[curr+square_rownum-1][curc+square_colnum]-matrixsum[curr+square_rownum][curc-1]+matrixsum[curr+square_rownum-1][curc-1]!=0){
                                    flg=false;
                                }
                                if(flg){
                                    dist[nextr][nextc]=dist[curr][curc]+1;
                                    q.push({nextr,nextc});
                                }
                            }
                            break;
                        case 1:
                            if(1<=curr-1){
                                if(matrixsum[curr-1][curc+square_colnum-1]-matrixsum[curr-1][curc-1]-matrixsum[curr-2][curc+square_colnum-1]+matrixsum[curr-2][curc-1]!=0){
                                    flg=false;
                                }
                                if(flg){
                                    dist[nextr][nextc]=dist[curr][curc]+1;
                                    q.push({nextr,nextc});
                                }
                            }
                            break;
                        case 2:
                            if(curc+square_colnum<=colnum){
                                if(matrixsum[curr+square_rownum-1][curc+square_colnum]-matrixsum[curr+square_rownum-1][curc+square_colnum-1]-matrixsum[curr-1][curc+square_colnum]+matrixsum[curr-1][curc+square_colnum-1]!=0){
                                    flg=false;
                                }
                                if(flg){
                                    dist[nextr][nextc]=dist[curr][curc]+1;
                                    q.push({nextr,nextc});
                                }
                            }
                            break;
                        case 3:
                            if(1<=curc-1){
                                if(matrixsum[curr+square_rownum-1][curc-1]-matrixsum[curr+square_rownum-1][curc-2]-matrixsum[curr-1][curc-1]+matrixsum[curr-1][curc-2]!=0){
                                    flg=false;
                                }
                                if(flg){
                                    dist[nextr][nextc]=dist[curr][curc]+1;
                                    q.push({nextr,nextc});
                                }
                            }
                            break;
                    }
                    if(nextr==target_r && nextc==target_c){
                        tmpflg=true;
                        break;
                    }
                }
            }
        }
        if(tmpflg){
            break;
        }
    }

    cout << dist[target_r][target_c] << '\n';

    return 0;
}