#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int parent[100001];
vector<int>adjlist[100001];
queue<int>q;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for(int k=1;k<n;k++){
        int a,b;
        cin >> a >> b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    q.push(1);
    parent[1]=-1;
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(auto& k : adjlist[cur]){
            int next=k;
            if(parent[k]==0){
                parent[next]=cur;
                q.push(next);
            }
        }
    }

    for(int k=2;k<=n;k++){
        cout << parent[k] << '\n';
    }
    
    return 0;
}