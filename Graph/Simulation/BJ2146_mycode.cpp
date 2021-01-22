#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int sizet;

int dist[101][101];
int territory[101][101];

int dr[4]={1,0,-1,0};
int dc[4]={0,1,0,-1};

void find_my_territory(int curr,int curc,int ter){
    territory[curr][curc]= ter;

    for(int k=0;k<4;k++){
        int nextr=curr+dr[k];
        int nextc=curc+dc[k];
        if(1<=nextr && nextr<=sizet && 1<=nextc && nextc<=sizet){
            if(dist[nextr][nextc]==1 && territory[nextr][nextc]==0){
                find_my_territory(nextr,nextc,ter);
            }
        }
    }
}

int main(){
    // getting input
    cin >> sizet;

    for(int r=1;r<=sizet;r++){
        for(int c=1;c<=sizet;c++){
            cin >> dist[r][c];
        }
    }
    
    // dividing territory number
    int cnt=1;
    for(int r=1;r<=sizet;r++){
        for(int c=1;c<=sizet;c++){
            if(dist[r][c]==1 && territory[r][c]==0){
                find_my_territory(r,c,cnt);
                cnt++;
            }
        }
    }
    
    // redefining the distance information
    for(int r=1;r<=sizet;r++){
        for(int c=1;c<=sizet;c++){
            if(dist[r][c]==1) dist[r][c]=0;
            else dist[r][c]=-1;
        }
    }
    
    queue<pair<int,int>>q;
    for(int r=1;r<=sizet;r++){
        for(int c=1;c<=sizet;c++){
            if(dist[r][c]==0){
                q.push({r,c});
            }
        }
    }
    
    while(!q.empty()){
        int curr=q.front().first;
        int curc=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            if(1<=nextr&&nextr<=sizet&&1<=nextc&&nextc<=sizet){
                if(dist[nextr][nextc]==-1){
                    dist[nextr][nextc]=dist[curr][curc]+1;
                    territory[nextr][nextc]=territory[curr][curc];
                    q.push({nextr,nextc});
                }
            }
        }
    }
    
    int answ=100000000;
    for(int r=1;r<=sizet;r++){
        for(int c=1;c<=sizet;c++){
            for(int k=0;k<4;k++){
                if(1<=r+dr[k] && r+dr[k]<=sizet && 1<=c+dc[k] && c+dc[k]<=sizet){
                    if(territory[r][c] != territory[r+dr[k]][c+dc[k]]){
                        if(answ==100000000 || dist[r][c]+dist[r+dr[k]][c+dc[k]]<answ){
                            answ= dist[r][c]+dist[r+dr[k]][c+dc[k]];
                        }
                    }
                }
            }
        }
    }

    cout << answ << '\n';
    
    return 0;
}