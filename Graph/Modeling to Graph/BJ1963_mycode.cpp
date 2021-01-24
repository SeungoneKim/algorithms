#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

int prime[10000];
bool check[10000];
int dist[10000];

int main(){
    
    int pn=0;
    for(int k=2;k<10000;k++){
        if(check[k]==false){
            prime[pn++]=k;

            for(int i=k*k;i<10000;i+=k){
                check[i] = true;
            }
        }
    }

    int tc;
    cin >> tc;

    while(tc--){
        int before,after;
        cin >> before >> after;

        if(before==after){
            cout << 0 << '\n';
            continue;
        }

        memset(dist,-1,sizeof(dist));

        queue<int>q;
        dist[before]=0;
        q.push(before);

        while(!q.empty()){
            int cur= q.front();
            q.pop();
            
            for(int k=0;k<4;k++){
                for(int t=0;t<10;t++){
                    if(!(t==0 && k==0)){
                        int tmpint=cur;
                        string tmpstr=to_string(tmpint);
                        tmpstr[k]=t+'0';
                        int next = stoi(tmpstr);
                        if(!check[next]){
                            if(dist[next]==-1){
                                q.push(next);
                                dist[next]=dist[cur]+1;
                            }
                        }
                    }
                }
            }
        }
        cout << dist[after] << '\n';

    }

    return 0;
}