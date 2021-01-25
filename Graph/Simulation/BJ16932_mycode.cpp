#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int rownum,colnum;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

int matrix[1001][1001];
int group[1001][1001];
int howmuch_in_group[1001];

void bfs(int initr,int initc,int groupnum){
    group[initr][initc]=groupnum;
    howmuch_in_group[groupnum]=1;

    queue<pair<int,int>>q;
    q.push({initr,initc});
    while(!q.empty()){
        int curr=q.front().first;
        int curc=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(group[nextr][nextc]==0 && matrix[nextr][nextc]==1){
                    group[nextr][nextc]=groupnum;
                    howmuch_in_group[groupnum]++;
                    q.push({nextr,nextc});
                }
            }
        }
    }
}

int main(){

    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
        }
    }

    int gn=1;
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(matrix[r][c]==1){
                if(group[r][c]==0){
                    bfs(r,c,gn);
                    gn++;
                }
            }
        }
    }
    gn--;
    
    int answ=0;
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(matrix[r][c]==0){
                int tmp=1;
                vector<int>included_group;
                for(int k=0;k<4;k++){
                    int checkr=r+dr[k];
                    int checkc=c+dc[k];
                    if(1<=checkr && checkr<=rownum && 1<=checkc && checkc<=colnum){
                        if(matrix[checkr][checkc]==1){
                            included_group.push_back(group[checkr][checkc]);
                        }
                    }
                }
                sort(included_group.begin(),included_group.end());
                included_group.erase(unique(included_group.begin(),included_group.end()),included_group.end());
                for(int neighbor : included_group){
                    tmp += howmuch_in_group[neighbor];
                }
                if(tmp>answ){
                    answ=tmp;
                }
            }
        }
    }

    cout << answ << '\n';

    return 0;
}