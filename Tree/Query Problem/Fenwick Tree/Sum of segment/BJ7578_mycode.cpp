#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>

using namespace std;

int tree[500001];
int a[500001];

int n;

void update(int i,int num){
    while(i<=n){
        tree[i] += num;
        i += (i & -i);
    }
}

int sum(int i){
    int answ=0;
    while(i>0){
        answ += tree[i];
        i -= (i & -i);
    }
    return answ;
}

int sum(int i,int r){
    if(i>r) return 0;
    return sum(r)-sum(i-1);
}

int main(){

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }    
    map<int,int>position;
    for(int i=0;i<n;i++){
        int tmp;
        cin >> tmp;
        position[tmp]=i+1;
    }

    long long answ=0;
    for(int i=0;i<n;i++){
        answ += (long long)sum(position[a[i]]+1,n);
        update(position[a[i]],1);
    }

    cout << answ << '\n';


    return 0;
}