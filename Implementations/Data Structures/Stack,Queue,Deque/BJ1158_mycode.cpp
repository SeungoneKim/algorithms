#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

queue <int> q;
vector <int> v;

int main(){
    
    int n,k;
    cin >> n >> k;
    
    for(int t=1;t<=n;t++){
        q.push(t);
    }
    
    while(!q.empty()){
        for(int t=1;t<=k-1;t++){
            int tmp = q.front();
            q.pop();
            q.push(tmp);
        }
        int tmp = q.front();
        q.pop();
        v.push_back(tmp);
    }
    
    cout << '<';
    for(int k=0;k<v.size()-1;k++){
        cout << v[k] << ", ";
    }
    cout << v[v.size()-1]<< '>';
    
    return 0;
}