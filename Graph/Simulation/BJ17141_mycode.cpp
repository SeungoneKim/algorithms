#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int matrix[51][51];
int dist[51][51];

int infinity=100000000;
int answ_time=infinity;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int size,howmany_virus;
    cin >> size >> howmany_virus;

    int cnt=0;
    vector<pair<int,int>> potential_virus_spot;
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            cin >> matrix[r][c];
            if(matrix[r][c]==2){
                potential_virus_spot.push_back({r,c});
                cnt++;
            }
        }
    }

    vector<int>permu(cnt);
    for(int k=0;k<cnt;k++){
        if(k<howmany_virus){
            permu[k]=1;
        }
        else{
            permu[k]=0;
        }
    }

    do{ 
        for(int r=1;r<=size;r++){
            for(int c=1;c<=size;c++){
                dist[r][c]=infinity;
            }
        }
        queue<pair<int,int>>q;
        for(int k=0;k<cnt;k++){
            if(permu[k]==1){
                q.push(potential_virus_spot[k]);
                dist[potential_virus_spot[k].first][potential_virus_spot[k].second]=0;
            }
        }

        while(!q.empty()){
            int curr=q.front().first;
            int curc=q.front().second;
            q.pop();

            for(int k=0;k<4;k++){
                int nextr=curr+dr[k];
                int nextc=curc+dc[k];
                if(1<=nextr && nextr<=size && 1<=nextc && nextc<=size){
                    if(matrix[nextr][nextc]==0 || matrix[nextr][nextc]==2){
                        if(dist[nextr][nextc]>dist[curr][curc]+1){
                            q.push({nextr,nextc});
                            dist[nextr][nextc]=dist[curr][curc]+1;
                        }
                    }
                }
            }
        }
        int tmp=0;
        bool acceptable=true;
        for(int r=1;r<=size;r++){
            for(int c=1;c<=size;c++){
                if(dist[r][c]==infinity && matrix[r][c]!=1){
                    acceptable=false;
                }
                else if(dist[r][c]!=infinity){
                    if(dist[r][c]>tmp){
                        tmp=dist[r][c];
                    }
                }
            }
        }
        if(acceptable){
            if(tmp<answ_time){
                answ_time=tmp;
            }
        }

    }while(prev_permutation(permu.begin(),permu.end()));

    if(answ_time==infinity){
        answ_time=-1;
    }

    cout << answ_time << '\n';

    return 0;
}