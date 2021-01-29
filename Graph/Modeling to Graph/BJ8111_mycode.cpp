#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;

        vector<bool>found(n,false);
        vector<int>from(n,-1);
        vector<int>how(n,-1);
        vector<int>dist(n,-1);

        found[1%n]=true;
        how[1%n]=1;
        dist[1%n]=1;
        
        queue<int>q;
        q.push(1%n);
        while(!q.empty()){
            int cur=q.front();
            q.pop();

            int next1=(cur*10)%n;
            if(dist[next1]==-1){
                from[next1]=cur;
                how[next1]=0;
                dist[next1]=dist[cur]+1;
                found[next1]=true;
                if(next1==0){
                    break;
                }
                q.push(next1);
            }

            int next2=((cur*10)+1)%n;
            if(dist[next2]==-1){
                from[next2]=cur;
                how[next2]=1;
                dist[next2]=dist[cur]+1;
                found[next2]=true;
                if(next2==0){
                    break;
                }
                q.push(next2);
            }
        }

        if(found[0]==false){
            cout << "BRAK" << '\n';
        }
        else{
            int tracking=0;

            string answ="";
            while(dist[tracking]>0){
                answ += to_string(how[tracking]);
                tracking=from[tracking];
            }
            reverse(answ.begin(),answ.end());
            cout << answ << '\n';
        }
    }


    return 0;
}