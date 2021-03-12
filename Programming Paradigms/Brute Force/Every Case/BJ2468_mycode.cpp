#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101][101];
bool drown[101][101];
int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

void bfs(int r,int c,int threshold){
    queue<pair<int,int>>q;
    q.push({r,c});
    drown[r][c]=true;

    while(!q.empty()){
        int curr= q.front().first;
        int curc= q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nextr= curr+dr[i];
            int nextc= curc+dc[i];
            if(0<=nextr && nextr<n && 0<=nextc && nextc<n){
                if(arr[nextr][nextc]>threshold){
                    if(!drown[nextr][nextc]){
                        drown[nextr][nextc]=true;
                        q.push({nextr,nextc});
                    }
                }
            }
        }
    }
}

int search(int threshold){
    memset(drown,false,sizeof(drown));
    int answ=0;

    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            if(arr[r][c]>threshold){
                if(!drown[r][c]){
                    answ++;
                    bfs(r,c,threshold);
                }
            }
        }
    }
    return answ;
}

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int minh=150,maxh=-1;

    cin >> n;
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            cin >> arr[r][c];
            if(arr[r][c]>maxh) maxh=arr[r][c];
            if(arr[r][c]<minh) minh=arr[r][c];
        }
    }

    int answ=0;
    for(int h=0;h<=maxh+1;h++){
        int tmpansw= search(h);

        if(tmpansw>answ) answ=tmpansw;
    }    

    cout << answ << '\n';

    return 0;
}