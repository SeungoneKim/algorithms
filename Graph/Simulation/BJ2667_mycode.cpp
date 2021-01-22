#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int matrix[26][26];
int check[26][26];
int cnt=1;

void bfs(int r, int c, int& cnt, int& size){
    
    check[r][c]=cnt;

    queue<pair<int,int>>q;
    q.push(make_pair(r,c));

    while(!q.empty()){
        int curr=q.front().first;
        int curc=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nextr=curr+dx[k];
            int nextc=curc+dy[k];
            if(1<=nextr && nextr<=size && 1<=nextc && nextc<=size){
                if(matrix[nextr][nextc]==1 && check[nextr][nextc]==0){
                    q.push(make_pair(nextr,nextc));
                    check[nextr][nextc]=cnt;
                }
            }
        }
    }
}

int main(){
    int size;
    cin >> size;
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            scanf("%1d",&matrix[r][c]);
        }
    }

    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            if(matrix[r][c]==1 && check[r][c]==0){
                bfs(r,c,cnt,size);
                cnt++;
            }
        }
    }
    
    cout << cnt-1 << '\n';

    vector<int>v(cnt-1);

    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            if(check[r][c]!=0){
                v[check[r][c]-1]++;
            }
        }
    }

    sort(v.begin(),v.end());
    for(int k=0;k<cnt-1;k++){
        cout << v[k] << '\n';
    }
    
    return 0;
}