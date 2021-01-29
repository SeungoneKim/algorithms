#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int howmuch_time[10001];
vector<int> must_do_first[10001];
int indegree[10001];
int answ[10001];
queue<int>q;

int main(){

    int vertex;
    cin >> vertex;

    for(int k=1;k<=vertex;k++){
        cin >> howmuch_time[k];
        int n;
        cin>> n;
        while(n--){
            int tmp=0;
            cin >> tmp;
            must_do_first[tmp].push_back(k);
            indegree[k]++;
        }
    }

    for(int k=1;k<=vertex;k++){
        if(indegree[k]==0){
            q.push(k);
            answ[k]=howmuch_time[k];
        }
    }
    
    while(!q.empty()){
        int cur=q.front();
        q.pop();

        for(int k=0;k<must_do_first[cur].size();k++){
            int next=must_do_first[cur][k];
            answ[next] = max(answ[next],answ[cur]+howmuch_time[next]);
            indegree[next]--;
            if(indegree[next]==0){
                q.push(next);
            }
        }
    }
    
    int real_answ=0;
    
    for(int k=1;k<=vertex;k++){
        if(real_answ<answ[k]) real_answ=answ[k];
    }

    cout << real_answ << '\n';

    return 0;
}