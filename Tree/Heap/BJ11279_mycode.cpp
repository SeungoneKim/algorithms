#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int>pq;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int operation;
    cin >> operation;

    for(int k=1;k<=operation;k++){
        int a;
        cin >> a;
        if(a==0){
            if(pq.size()>0){
                cout << pq.top() << '\n';
                pq.pop();
            }
            else{
                cout << 0 << '\n';
            }
        }
        else{
            pq.push(a);
        }
    }


    return 0;
}
