#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[2001];
bool pel[2001][2001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len;
    cin >> len;

    for(int k=1;k<=len;k++){
        cin >> arr[k];
    }

    for(int k=1;k<=len;k++){
        pel[k][k]=true;
    }
    for(int k=1;k<len;k++){
        if(arr[k]==arr[k+1]){
            pel[k][k+1]=true;
        }
    }
    for(int l=3;l<=len;l++){
        for(int s=1;s<=len-l+1;s++){
            int e=s+l-1;
            if(pel[s+1][e-1] && arr[s]==arr[e]){
                pel[s][e]=true;
            }
        }
    }

    int query;
    cin>> query;
    while(query--){
        int a,b;
        cin >> a >> b;
        if(pel[a][b]){
            cout << 1 << '\n';
        }
        else{
            cout << 0 << '\n';
        }
    }

    return 0;
}