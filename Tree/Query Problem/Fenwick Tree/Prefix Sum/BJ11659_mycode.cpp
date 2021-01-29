#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int numbers[100001];
int sum[100001];

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len,query;
    cin >> len >> query;

    for(int k=1;k<=len;k++){
        cin >> numbers[k];
    }
    sum[1]=numbers[1];
    for(int k=2;k<=len;k++){
        sum[k]=sum[k-1]+numbers[k];
    }

    while(query--){
        int a,b;
        cin >> a >> b;

        cout << sum[b]-sum[a-1] << '\n';
    }

    return 0;
}