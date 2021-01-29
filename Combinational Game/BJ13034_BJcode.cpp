#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

int g[1001];

int main(){

    int n;
    cin >> n;

    for(int i=0;i<=n;i++){
        set<int>s;
        for(int j=0;j<=i-2;j++){
            s.insert(g[j]^g[i-2-j]);
        }
        for(int j=0;;j++){
            if(s.count(j)==0){
                g[i]=j;
                break;
            }
        }
    }
    if(g[n]==0){
        cout << 2 << '\n';
    }
    else{
        cout << 1 << '\n';
    }

    return 0;
}