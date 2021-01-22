#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int matrix[1001][1001];
int check[1001][1001];

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int infin=100000000;

queue<pair<int,int>> q;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int colnum, rownum;
    cin >> colnum >> rownum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
        }
    }

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(matrix[r][c]==0){
                check[r][c]=infin;
            }
        }
    }

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(matrix[r][c]==1){
                q.push(make_pair(r,c));
                check[r][c]=0;
            }
        }
    }

    while(!q.empty()){
        int curr=q.front().first;
        int curc=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int nextr=curr+dx[k];
            int nextc=curc+dy[k];
            if(1<=nextr&&nextr<=rownum&&1<=nextc&&nextc<=colnum){
                if(matrix[nextr][nextc]==0 && check[nextr][nextc]>check[curr][curc]+1){
                    q.push(make_pair(nextr,nextc));
                    check[nextr][nextc] = check[curr][curc]+1;
                }
            }
        }
    }
    
    int answ=0;
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            if(check[r][c]>answ)
                answ=check[r][c];
        }
    }
    if(answ==infin){
        answ=-1;
    }

    cout << answ << '\n';

    return 0;
}