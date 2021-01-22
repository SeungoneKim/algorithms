#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

vector<int> adjlist[20001];
int check[20001];

void dfs(int cur, int color){
    check[cur]=color;

    for(int k=0;k<adjlist[cur].size();k++){
        int next= adjlist[cur][k];
        if(check[next]==0){
            dfs(next,3-color);
        }
    }
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;

    while(tc--){
        int vertex,edge;
        cin >> vertex >> edge;
        for(int k=0;k<edge;k++){
            int a,b;
            cin >> a >> b;
            adjlist[a].push_back(b);
            adjlist[b].push_back(a);
        }

        for(int k=1;k<=vertex;k++){
            if(check[k]==0){
                dfs(k,1);
            }
        }

        bool answ=true;
        for(int k=0;k<vertex;k++){
            int c1 = check[k];
            for(int t=0;t<adjlist[k].size();t++){
                int c2 = check[adjlist[k][t]];
                if(c1 == c2)
                    answ=false;
            }
        }
        if(answ==false){
            cout << "NO" << '\n';
        }
        else{
            cout << "YES" << '\n';
        }

        //initializing the global members
        for(int k=1;k<=vertex;k++){
            adjlist[k].clear();
            check[k] =0;
        }
        
    }

    return 0;
}