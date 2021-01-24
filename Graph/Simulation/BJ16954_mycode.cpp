#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

int dr[9]={1,1,1,0,0,0,-1,-1,-1};
int dc[9]={1,0,-1,1,0,-1,1,0,-1};

int matrix[9][9];
int visited[9][9][9];

queue<tuple<int,int,int>> q;

int main(){

    for(int r=1;r<=8;r++){
        for(int c=1;c<=8;c++){
            char x;
            cin >> x;
            if(x=='.'){
                matrix[r][c]=0;
            }
            else{
                matrix[r][c]=1;
            }
        }
    }
    
    q.push({8,1,0});
    visited[8][1][0]=true;
    bool answ=false;

    while(!q.empty()){
        int curr=get<0>(q.front());
        int curc=get<1>(q.front());
        int curt=get<2>(q.front());
        q.pop();
        // cout << curr << ' '<< curc << ' ' << curt << '\n';
        if(curr==1 && curc==8) answ=true;

        for(int k=0;k<9;k++){
            int nextr=curr+dr[k];
            int nextc=curc+dc[k];
            int nextt=min(curt+1,8);
            
            if(1<=nextr && nextr<=8 && 1<=nextc && nextc<=8){
                
                    
                    if(matrix[nextr-curt-1][nextc]== 1 && 1<=nextr-curt-1) continue;
                    if(matrix[nextr-curt][nextc]==1 && 1<=nextr-curt) continue; 

                    if(visited[nextr][nextc][nextt]==false){
                        visited[nextr][nextc][nextt]=true;
                        q.push(make_tuple(nextr,nextc,nextt));
                        
                    }
                    
                
            }
        }
    }

    if(answ){
        cout << 1 << '\n';
    }
    else{
        cout << 0 << '\n';
    }


    return 0;
}