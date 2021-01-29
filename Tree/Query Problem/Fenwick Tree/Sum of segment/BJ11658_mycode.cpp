#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int matrix[1025][1025];
int tree[1025][1025];

int size,query;

void update(int x, int y, int val) {
    for (int i=x; i<=size; i+=i&-i) {
        for (int j=y; j<=size; j+=j&-j) {
            tree[i][j] += val;
        }
    }
}
int sum(int x, int y) {
    int ans = 0;
    for (int i=x; i>0; i-=i&-i) {
        for (int j=y; j>0; j-=j&-j) {
            ans += tree[i][j];
        }
    }
    return ans;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> size >> query;

    for(int i=1;i<=size;i++){
        for(int j=1;j<=size;j++){
            cin >> matrix[i][j];
            update(i,j,matrix[i][j]);
        }
    }

    while(query--){
        int which;
        cin >> which;
        if(which==0){
            int x,y,val;
            cin >> x >> y >> val;
            update(x,y,val-matrix[x][y]);
            matrix[x][y]=val;
        }
        else{
            int x1,y1,x2,y2;
            cin >> x1 >> y1 >> x2 >> y2;
            long long answ= sum(x2,y2)-sum(x1-1,y2)-sum(x2,y1-1)+sum(x1-1,y1-1);
            cout << answ << '\n';
        }
    }

    return 0;
}