#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <climits>
#include <bitset>

using namespace std;

int rownum,colnum;
int carnum=0,parknum=0;
char a[50][50];

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

struct MaximumFlow{
    int n;
    int source,sink;
    vector<vector<int>>graph;
    vector<bool>check;
    vector<int>pred;
    MaximumFlow(int n): n(n)
    {
        graph.resize(n);
        check.resize(n);
        pred.resize(n,-1); 
    };

    void add_edge(int u,int v){
        graph[u].push_back(v);
    }
    bool dfs(int x){
        if(x==-1) return true;
        
        for(int next : graph[x]){
            if(check[next]) continue;
            check[next]=true;
            if(dfs(pred[next])){ // since pred[next]==-1 at initialization, it will return true if going to sink
                pred[next]=x;
                return true;
            }
        }
        return false;
    }
    int flow(){
        int answ=0;
        for(int i=0;i<carnum;i++){
            fill(check.begin(),check.end(),false);
            if(dfs(i)){
                answ+=1;
            }
        }
        return answ;
    }
};

int main(){

    cin >> rownum >> colnum;

    vector<pair<int,int>>carpos;
    vector<pair<int,int>>parkpos;
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cin >> a[r][c];
            if(a[r][c]=='C'){
                carnum++;
                carpos.push_back({r,c});
            }
            if(a[r][c]=='P'){
                parknum++;
                parkpos.push_back({r,c});
            }
        }
    }

    if(parknum<carnum){
        cout << -1 << '\n';
        return 0;
    }
    if(carnum==0){
        cout << 0 << '\n';
        return 0;
    }

    vector<vector<int>>time(carnum,vector<int>(parknum));
    for(int i=0;i<carnum;i++){
        queue<pair<int,int>>q;
        vector<vector<int>>dist(rownum,vector<int>(colnum,-1));
        auto start=carpos[i];
        q.push(start);
        dist[start.first][start.second]=0;

        while(!q.empty()){
            auto cur= q.front();
            q.pop();

            for(int k=0;k<4;k++){
                int nextr=cur.first+dr[k];
                int nextc=cur.second+dc[k];
                if(0<=nextr && nextr<rownum && 0<=nextc && nextc<colnum){
                    if(a[nextr][nextc]!='X'){
                        if(dist[nextr][nextc]==-1){
                            q.push({nextr,nextc});
                            dist[nextr][nextc]=dist[cur.first][cur.second]+1;
                        }
                    }
                }
            }
        }
        for(int j=0;j<parknum;j++){
            time[i][j]= dist[parkpos[j].first][parkpos[j].second];
        }
    }

    int left=1;
    int right=rownum*colnum;
    int answ=rownum*colnum+1;
    int impossible=rownum*colnum+1;

    while(left<=right){
        int mid = (left+right)/2;
        MaximumFlow mf(max(carnum,parknum));
        for(int i=0;i<carnum;i++){
            for(int j=0;j<parknum;j++){
                if(time[i][j]!=-1 && time[i][j]<=mid){
                    mf.add_edge(i,j);
                }
            }
        }
        if(mf.flow()==carnum){
            answ= min(answ,mid);
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }

    if(answ==impossible){
        answ=-1;
    }
    
    cout << answ << '\n';

    return 0;
}