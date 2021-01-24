#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cstring>
#include <queue>

using namespace std;

int rownum, colnum;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

char matrix[51][51];
int waterdist[51][51];
int animaldist[51][51];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> rownum >> colnum;

    for(int k=1;k<=rownum;k++){
        memset(waterdist[k],-1,sizeof(waterdist[k]));
    }
    queue<tuple<int,int,int>>q;
    
    int animal_startr, animal_startc;
    int animal_endr, animal_endc;

    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cin >> matrix[r][c];
            if(matrix[r][c]=='*'){
                q.push(make_tuple(r,c,0));
                waterdist[r][c]=0;
            }
            else if(matrix[r][c]=='S'){
                animal_startr=r;
                animal_startc=c;
            }
            else if(matrix[r][c]=='D'){
                animal_endr=r;
                animal_endc=c;
            }
        }
    }

    // first, we fill out the matrix with distance info of when the water will get filled.

    while(!q.empty()){
        int curr= get<0>(q.front());
        int curc= get<1>(q.front());
        int curd= get<2>(q.front());
        q.pop();

        for(int k=0;k<4;k++){
            int nextr= curr+dr[k];
            int nextc= curc+dc[k];
            int nextd= curd+1;
            
            if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(waterdist[nextr][nextc]==-1 || waterdist[nextr][nextc]>nextd){
                    if(matrix[nextr][nextc]!='D' && matrix[nextr][nextc]!='X' && matrix[nextr][nextc]!='*'){
                        waterdist[nextr][nextc]= nextd;
                        q.push(make_tuple(nextr,nextc,nextd));
                    }
                }
            }
        }
    }

    // next, using bfs, we seek if the animal could move to the goal according to the information of the waterdist
    queue<tuple<int,int,int>>q2;
    
    for(int k=1;k<=rownum;k++){
        memset(animaldist[k],-1,sizeof(animaldist[k]));
    }

    q2.push(make_tuple(animal_startr,animal_startc,0));
    animaldist[animal_startr][animal_startc]=0;

    while(!q2.empty()){
        int curr= get<0>(q2.front());
        int curc= get<1>(q2.front());
        int curd= get<2>(q2.front());
        q2.pop();

        if(curr==animal_endr && curc==animal_endc){
            cout << animaldist[curr][curc] << '\n';
            return 0;
        }

        for(int k=0;k<4;k++){
            int nextr= curr+dr[k];
            int nextc= curc+dc[k];
            int nextd= curd+1;
            
            if(1<=nextr && nextr<=rownum && 1<=nextc && nextc<=colnum){
                if(animaldist[nextr][nextc]==-1){
                    if(matrix[nextr][nextc]!='X'){
                        if(waterdist[nextr][nextc]==-1 || waterdist[nextr][nextc]>nextd){
                            animaldist[nextr][nextc]=nextd;
                            q2.push(make_tuple(nextr,nextc,nextd));
                        }
                        
                    }
                }
            }
        }
    }
    /*
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cout << waterdist[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    for(int r=1;r<=rownum;r++){
        for(int c=1;c<=colnum;c++){
            cout << animaldist[r][c] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
    */

    cout << "KAKTUS" << '\n';

    return 0;
}