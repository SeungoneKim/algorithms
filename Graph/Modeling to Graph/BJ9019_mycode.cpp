#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

int dist[10000];
int beforenum[10000];
char how[10000];

int tmpt[4];
char method[4]={'D','S','L','R'};

queue<int>q;

int main(){

    int tc;
    cin >> tc;

    while(tc--){
        int before,after;
        cin >> before >> after;

        memset(dist,-1,sizeof(dist));
        memset(beforenum,-1,sizeof(beforenum));
        memset(how,'-',sizeof(how));

        q.push(before);
        dist[before]=0;

        while(!q.empty()){
            int cur=q.front();
            q.pop();

            tmpt[0]= (cur*2) %10000;
            tmpt[1]= 0;
            cur-1>=0 ? tmpt[1]=cur-1 : tmpt[1]=9999;
            tmpt[2]= (cur%1000)*10 + (cur/1000);
            tmpt[3]= (cur/10) + (cur%10)*1000;

            for(int k=0;k<4;k++){
                if(0<=tmpt[k] && tmpt[k]<10000){
                    if(dist[tmpt[k]]==-1){
                        q.push(tmpt[k]);
                        dist[tmpt[k]]=dist[cur]+1;
                        beforenum[tmpt[k]]=cur;
                        how[tmpt[k]]=method[k];
                    }
                }
            }
        }

        int len= dist[after];

        string s;
        int now=after;
        for(int k=len;k>0;k--){
            s += how[now];
            now=beforenum[now];
        }
        reverse(s.begin(),s.end());
        
        cout << s << '\n';
    }

    return 0;
}