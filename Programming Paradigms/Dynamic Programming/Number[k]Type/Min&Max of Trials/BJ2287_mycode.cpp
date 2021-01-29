#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <climits>

using namespace std;

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;

    set<int>s[9];
    int num=0;
    for(int i=1;i<=8;i++){
        num = num*10+k; 
        s[i].insert(num);
    }
    // dynamic using set
    for(int i=2;i<=8;i++){
        for(int j=1;j<i;j++){
            int t=i-j;
            for(int x:s[j]){
                for(int y:s[t]){
                    s[i].insert(x+y);
                    s[i].insert(x-y);
                    s[i].insert(x*y);
                    if(y!=0) s[i].insert(x/y);
                }
            }
        }
    }

    int tc;
    cin >> tc;
    while(tc--){
        int targetnum;
        cin >> targetnum;
        
        bool found =false;
        for(int i=1;i<=8;i++){
            if(s[i].count(targetnum)>0){
                cout << i << '\n';
                found=true;
                break;
            }
        }
        if(!found){
            cout << "NO\n";
        }
    }

    return 0;
}