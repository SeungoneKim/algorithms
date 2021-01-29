#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int>adjlist[32001];
int indegree[32001];
priority_queue<int>pq;

int main(){

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
            pq.push(-k);
        }
    }

    while(!pq.empty()){
        int cur=pq.top();
        cur = -cur;
        pq.pop();
        cout << cur << ' ';

        for(int k=0;k<adjlist[cur].size();k++){
            int next=adjlist[cur][k];
            indegree[next]--;
            if(indegree[next]==0){
                pq.push(-next);
            }
        }
    }
    cout << '\n';

    return 0;
}