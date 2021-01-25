#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int matrix[201][201];
int dist[201][201][31];

queue<tuple<int,int,int>>q; // {nextr,nextc,ntalh}
int infinity=100000000;

int horse_dr[8]={-2,-1,1,2,2,1,-1,-2};
int horse_dc[8]={1,2,2,1,-1,-2,-2,-1};
int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

int main(){

    int num_to_act_like_horse;
    cin >> num_to_act_like_horse;

    int colnum,rownum;
    cin >> colnum >> rownum;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
        }
    }
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            for(int k=0;k<=num_to_act_like_horse;k++){
                dist[r][c][k]= infinity;
            }
        }
    }

    dist[1][1][0]=0;
    q.push(make_tuple(1,1,0));
    
    while(!q.empty()){
        int curr=get<0>(q.front());
        int curc=get<1>(q.front());
        int cur_ntalh=get<2>(q.front());
        q.pop();

        if(cur_ntalh+1<=num_to_act_like_horse){
            for(int k=0;k<8;k++){
                int nextr=curr+horse_dr[k];
                int nextc=curc+horse_dc[k];
                int next_ntalh=cur_ntalh+1;
                if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                    if(matrix[nextr][nextc]!=1){
                        if(dist[nextr][nextc][next_ntalh]>dist[curr][curc][cur_ntalh]+1){
                            dist[nextr][nextc][next_ntalh]=dist[curr][curc][cur_ntalh]+1;
                            q.push(make_tuple(nextr,nextc,next_ntalh));
                        }
                    }
                }
            }
        }
        
        for(int k=0;k<4;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            int next_ntalh=cur_ntalh;
            if(1<= nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(matrix[nextr][nextc]!=1){
                    if(dist[nextr][nextc][next_ntalh]>dist[curr][curc][cur_ntalh]+1){
                        dist[nextr][nextc][next_ntalh]=dist[curr][curc][cur_ntalh]+1;
                        q.push(make_tuple(nextr,nextc,next_ntalh));
                    }
                }
            }
        }

    }

    int answ=infinity;
    for(int k=0;k<=num_to_act_like_horse;k++){
        if(dist[rownum][colnum][k]<answ){
            answ= dist[rownum][colnum][k];
        }
    }
    if(answ==infinity){
        answ=-1;
    }

    cout << answ << '\n';
    /*
    for(int k=0;k<=num_to_act_like_horse;k++){
        for(int r=1;r<=rownum;r++){
            for(int c=1;c<=colnum;c++){
                cout << dist[r][c][k] << ' ';
            }
            cout << '\n';
        }
        cout << '\n';
    }
    */
    return 0;
}