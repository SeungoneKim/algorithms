#include <iostream>
#include <deque>

using namespace std;

int dist[101][101];
bool visited[101][101];

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int colnum, rownum;
    cin >> colnum >> rownum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            char x;
            cin >> x;
            dist[r][c]=x-'0';

        }
    }

    deque<pair<int,int>>d;
    dist[1][1]=0;
    visited[1][1]=true;
    d.push_back({1,1});

    while(!d.empty()){

        int curr=d.front().first;
        int curc=d.front().second;
        d.pop_front();

        for(int k=0;k<4;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            if(!visited[nextr][nextc]){
                if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                    if(dist[nextr][nextc]==0){
                        visited[nextr][nextc]=true;
                        dist[nextr][nextc]=dist[curr][curc];
                        d.push_front({nextr,nextc});
                    }
                    else{
                        visited[nextr][nextc]=true;
                        dist[nextr][nextc]=dist[curr][curc]+1;
                        d.push_back({nextr,nextc});
                    }
                }
            }
        }
    }

    cout << dist[rownum][colnum] << '\n';

    return 0;
}