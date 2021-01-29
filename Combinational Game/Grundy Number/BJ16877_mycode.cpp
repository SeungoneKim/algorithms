#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int limit=3000000;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int>fibo={1,1};
    for(int i=2;;i++){
        int num=fibo[i-1]+fibo[i-2];
        if(num>limit) break;
        fibo.push_back(num);
    }
    vector<int>d(limit+1);
    for(int i=1;i<=limit;i++){
        vector<int>check(50);
        for(int j:fibo){
            if(i<j) break;
            check[d[i-j]]=1;
        }
        for(int k=0;;k++){
            if(check[k]==0){
                d[i]=k;
                break;
            }
        }
    }

    int n;
    cin >> n;
    int answ=0;
    while(n--){
        int x;
        cin >> x;
        answ ^= d[x];
    }
    if(answ==0){
        cout << "cubelover" << '\n';
    }
    else{
        cout << "koosaga" << '\n';
    }
    


    return 0;
}