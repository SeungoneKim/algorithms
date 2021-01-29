#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>

using namespace std;

int d[1000][1000];
int a[1000][1000];
int s[10];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<pair<int,int>>q[10];
queue<pair<int,int>>next_q[10];

int main(){

    int n,m,p;
    cin >> n >> m >> p;
    for(int i=1;i<=p;i++){
        cin >> s[i];
    }
    for(int i=0;i<n;i++){
        string line;
        cin >> line;
        for(int j=0;j<m;j++){
            if(line[j]=='.'){
                a[i][j]=0;
            }
            else if(line[j]=='#'){
                a[i][j]=-1;
            }
            else{
                a[i][j]=line[j]-'0';
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(a[i][j]>0){
                q[a[i][j]].push({i,j});
            }
        }
    }
    while(true){
        bool ok=false;
        for(int who=1;who<=p;who++){
            memset(d,0,sizeof(d));
            while(!q[who].empty()){
                ok=true;
                int x,y;
                tie(x,y)=q[who].front();
                q[who].pop();
                if(d[x][y] == s[who]){
                    next_q[who].push({x,y});
                }
                if(a[x][y]>0 && a[x][y]!=who){
                    continue;
                }
                a[x][y]=who;
                for(int k=0;k<4;k++){
                    int nx=x+dx[k];
                    int ny=y+dy[k];
                    if(0<=nx && nx<n && 0<=ny && ny<m){
                        if(a[nx][ny]==0){
                            d[nx][ny]=d[x][y]+1;
                            if(d[nx][ny]<=s[who]){
                                a[nx][ny]=who;
                                q[who].push({nx,ny});
                            }
                        }
                    }
                }
            }
            q[who]=next_q[who];
            next_q[who]=queue<pair<int,int>>();
        }
        if(!ok){
            break;
        }
    }
    vector<int> ans(p+1);
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (a[i][j] > 0) {
                ans[a[i][j]] += 1;
            }
        }
    }
    for (int i=1; i<=p; i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}