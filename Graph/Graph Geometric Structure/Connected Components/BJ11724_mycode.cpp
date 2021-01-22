#include <iostream>
#include <vector>

using namespace std;

vector<int> adjlist[1001];
bool check[1001];

void dfs(int cur){
    check[cur]=true;

    for(int k=0;k<adjlist[cur].size();k++){
        int next = adjlist[cur][k];
        if(check[next]==false){
            dfs(next);
        }
    }
}

int main(){
    int vertex,edge;
    cin >> vertex >> edge;

    for(int k=1;k<=edge;k++){
        int a,b;
        cin >> a >> b;

        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }

    int answ=0;
    for(int k=1;k<=vertex;k++){
        if(check[k]==false){
            dfs(k);
            answ++;
        }
    }

    cout << answ << '\n';
    return 0;
}