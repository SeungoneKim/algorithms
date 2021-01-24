#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>

using namespace std;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

int rownum,colnum;

int matrix[1001][1001];
int group[1001][1001];
int element_number_of_group[600000];
int answermatrix[1001][1001];

void bfs(int startr, int startc, int n){
    group[startr][startc]=n;
    queue<pair<int,int>>q;
    q.push({startr,startc});
    element_number_of_group[n]=1;

    while(!q.empty()){
        int curr=q.front().first;
        int curc=q.front().second;
        q.pop();

        for(int k=0;k<4;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(group[nextr][nextc]==0 && matrix[nextr][nextc]==0){
                    q.push({nextr,nextc});
                    group[nextr][nextc]=n;
                    element_number_of_group[n]++;
                }
            }
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> rownum >> colnum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            char x;
            cin >> x;
            matrix[r][c]=x-'0';
        }
    }

    int idx=1;
    for(int k=1;k<=rownum;k++){
        for(int t=1;t<=colnum;t++){
            if(matrix[k][t]==0 && group[k][t]==0){
                bfs(k,t,idx);
                idx++;
            }
        }
    }

    for(int k=1;k<=rownum;k++){
        for(int t=1;t<=colnum;t++){
            if(matrix[k][t]==1){
                set<int> near;
                for (int p=0; p<4; p++) {
                    int x = k+dr[p];
                    int y = t+dc[p];
                    if (1 <= x && x <= rownum && 1 <= y && y <= colnum) {
                        if (matrix[x][y] == 0) {
                            near.insert(group[x][y]);
                        }
                    }
                }
                int ans = 1;
                for (int g : near) {
                    ans += element_number_of_group[g];
                }
                
                answermatrix[k][t] = ans%10;
            }
            else{
                answermatrix[k][t]=0;
            }
        }
    }

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cout << answermatrix[r][c] %10;
        }
        cout << '\n';
    }


    return 0;
}