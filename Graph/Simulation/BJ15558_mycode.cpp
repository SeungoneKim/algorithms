#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <tuple>
#include <queue>

using namespace std;

int matrix[100001][2];
int dist[100001][2];
queue<tuple<int,int,int>>q;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len, k;
    cin >> len >> k;
    
    string line1;
    cin >> line1;
    for(int t=1;t<=len;t++){
        matrix[t][0]=line1[t-1]-'0';
    }

    string line2;
    cin >> line2;
    for(int t=1;t<=len;t++){
        matrix[t][1]=line2[t-1]-'0';
    }

    memset(dist,-1,sizeof(dist));
    dist[1][0]=0;
    q.push({1,0,0});

    while(!q.empty()){
        
        int cur_line,cur_position,cur_time;
        tie(cur_position,cur_line,cur_time)=q.front();
        q.pop();

        if(cur_position+1>=len || cur_position+k>=len){
            cout << 1 << '\n';
            return 0;
        }
        if(cur_position+1<len){
            if(matrix[cur_position+1][cur_line]==1 && dist[cur_position+1][cur_line]==-1){
                dist[cur_position+1][cur_line] = dist[cur_position][cur_line]+1;
                q.push({cur_position+1,cur_line,cur_time+1});
            }
        }
        if(cur_position-1>=1){
            if(matrix[cur_position-1][cur_line]==1 && cur_position-1>=cur_time && dist[cur_position-1][cur_line]==-1){
                dist[cur_position-1][cur_line] = dist[cur_position][cur_line]+1;
                q.push({cur_position-1,cur_line,cur_time+1});
            }
        }
        if(cur_position+k<len){
            if(matrix[cur_position+k][1-cur_line]==1 && dist[cur_position+k][1-cur_line]==-1){
                dist[cur_position+k][1-cur_line] = dist[cur_position][cur_line]+1;
                q.push({cur_position+k,1-cur_line,cur_time+1});
            }
        }
    }


    cout << 0 << '\n';

    return 0;
}