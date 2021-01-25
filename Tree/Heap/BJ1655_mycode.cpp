#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> leftside;
priority_queue<int, vector<int>, greater<int>>rightside;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    
    while(n--){
        int x;
        cin >> x;
        if(leftside.empty() || rightside.empty()){
            leftside.push(x);
        }
        else{
            if(x <= leftside.top()){
                leftside.push(x);
            }
            else if(x >= rightside.top()){
                rightside.push(x);
            }
            else{
                leftside.push(x);
            }
        }
        while(!(leftside.size()==rightside.size() || leftside.size() == rightside.size()+1)){
            if(leftside.size()>rightside.size()){
                rightside.push(leftside.top());
                leftside.pop();
            }
            else{
                leftside.push(rightside.top());
                rightside.pop();
            }
        }

        cout << leftside.top() << '\n';
    }


    return 0;
}