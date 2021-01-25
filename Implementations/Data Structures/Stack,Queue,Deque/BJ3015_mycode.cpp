#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int height_info[500001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<pair<int,int>>s;

    int n;
    cin >> n;
    for(int k=0;k<n;k++){
        cin >> height_info[k];
    }

    long long answ=0;
    for(int i=0;i<n;i++){
        pair<int,int>p={height_info[i],1};
        while(!s.empty()){
            if(s.top().first<=height_info[i]){
                answ += (long long)s.top().second;
                if(s.top().first==height_info[i]){
                    p.second += s.top().second;
                }
                s.pop();
            }
            else{
                break;
            }
        }
        if(!s.empty()){
            answ += 1LL;
        }
        s.push(p);
    }

    cout << answ << '\n';

    return 0;
}