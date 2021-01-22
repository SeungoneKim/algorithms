#include <iostream>
#include <vector>

using namespace std;

bool mat[2001][2001];
vector<int> adjlist[2001];
vector< pair<int,int> >edgelist;
// int cnt[2000];
/*
bool compare(const pair<int,int> a, const pair<int,int> b){
    if(a.first==b.first){
        return a.second < b.second;
    }
    return a.first < b. first;
}
*/
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int vertex,edge;
    cin >> vertex >> edge;

    for(int k=0;k<edge;k++){
        int a,b;
        cin >> a >> b;

        mat[a][b]=true;
        mat[b][a]=true;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
        edgelist.push_back(make_pair(a,b));
        // cnt[a]++;
        edgelist.push_back(make_pair(b,a));
        // cnt[b]++;
    }
    //sort(edgelist.begin(),edgelist.end(),compare);
    /*
    for(int k=1;k<=edge*2-1;k++){
        cnt[k] += cnt[k-1];
    }
    */
    
    edge *=2;

    for(int k=0;k<edge;k++){
        for(int j=0;j<edge;j++){
            int A = edgelist[k].first;
            int B = edgelist[k].second;
            int C = edgelist[j].first;
            int D = edgelist[j].second;

            if(A==B || A==C || A==D || B==C || B==D || C==D){
                continue;
            }
            if(mat[B][C]==false){
                continue;
            }
            for(int E : adjlist[D]){
                if(A==E || B==E || C==E || D==E){
                    continue;
                }
                cout << 1 << '\n';
                return 0;
            }
        }
    }

    cout << 0 << '\n';
    
    return 0;
}