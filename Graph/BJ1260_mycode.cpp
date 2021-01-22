#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adjlist[1000];
int checkdfs[1001];
int checkbfs[1001];

void dfs(int cur){
    checkdfs[cur]=true;
    cout << cur << ' ';

    for(int i=0;i<adjlist[cur].size();i++){
        int next = adjlist[cur][i];
        if(checkdfs[next]==false){
            dfs(next);
        }
    }
}

int main(){
    int vertex,edge,start;
    cin >> vertex >> edge >> start;

    for(int k=0;k<edge;k++){
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    // we first sort the adjacent list
    for(int k=0;k<vertex;k++){
        sort(adjlist[k].begin(),adjlist[k].end());
    }

    // we start with dfs
    dfs(start);
    cout << '\n';

    // we next do bfs
    queue<int>q;
    q.push(start); checkbfs[start]=true;

    while(!q.empty()){
        int cur = q.front();
        q.pop();
        cout << cur << ' ';

        for(int i=0;i<adjlist[cur].size();i++){
            int next= adjlist[cur][i];
            if(checkbfs[next]==false){
                checkbfs[next]=true;
                q.push(next);
            }
        }
    }
    cout << '\n';
    return 0;
}