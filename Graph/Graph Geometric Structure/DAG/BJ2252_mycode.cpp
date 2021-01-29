#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int>adjlist[32001];
int indegree[32001];
queue<int>q;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex,edge;
    cin >> vertex >> edge;

    for(int k=1;k<=edge;k++){
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        indegree[b]++;
    }

    for(int k=1;k<=vertex;k++){
        if(indegree[k]==0){
            q.push(k);
        }
    }
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        cout << cur << ' ';

        for(int k=0;k<adjlist[cur].size();k++){
            int next= adjlist[cur][k];
            indegree[next]--;
            if(indegree[next]==0){
                q.push(next);
            }
        }
    }
    cout << '\n';

    return 0;
}