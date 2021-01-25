#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int parent[101];
int rankk[101];

int Find(int x){
    if(x==parent[x]){
        return x;
    }
    else{
        int y= Find(parent[x]);
        parent[x]=y;
        return y;
    }
}

// Implementing Union function using Rank
void Union(int x, int y){
    x= Find(x);
    y= Find(y);
    if(x==y){
        return;
    }
    if(rankk[x]<rankk[y]) swap(x,y);
    parent[y]=x;
    if(rankk[x]==rankk[y]){
        rankk[x] = rankk[y]+1;
    }
}

int main(){

    int node,operation;
    cin >> node >> operation;

    for(int i=1;i<=node;i++){
        parent[i]=i;
        rankk[i]=1;
    }

    for(int k=1;k<=operation;k++){
        int a,b;
        cin >> a >> b;
        Union(a,b);
    }

    int answ=0;
    int c=Find(1);
    for(int k=2;k<=node;k++){
        int d=Find(k);
        if(c==d){
            answ++;
        }
    }
    
    cout << answ << '\n';

    return 0;
}