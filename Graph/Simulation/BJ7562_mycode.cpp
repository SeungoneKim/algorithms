#include <iostream>
#include <queue>

using namespace std;

int check[300][300];
queue <pair<int,int>> q;
int infi=100000000;

int dx[8]={2,2,1,1,-1,-1,-2,-2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};

int main(){

    int tc;
    cin >> tc;

    while(tc--){
        int size;
        int initr,initc;
        int tarr,tarc;
        cin >> size >> initr >> initc >> tarr >> tarc;

        for(int r=0;r<size;r++){
            for(int c=0;c<size;c++){
                check[r][c]=infi;
            }
        }

        q.push(make_pair(initr,initc));
        check[initr][initc]=0;

        while(!q.empty()){
            int curr = q.front().first;
            int curc = q.front().second;
            q.pop();

            for(int k=0;k<8;k++){
                int nextr=curr+dx[k];
                int nextc=curc+dy[k];

                if(0<=nextr&&nextr<size&&0<=nextc&&nextc<size){
                    if(check[nextr][nextc]>check[curr][curc]+1){
                        check[nextr][nextc]=check[curr][curc]+1;
                        q.push(make_pair(nextr,nextc));
                    }
                }
            }
        }

        cout << check[tarr][tarc] << '\n';

    }

    return 0;
}