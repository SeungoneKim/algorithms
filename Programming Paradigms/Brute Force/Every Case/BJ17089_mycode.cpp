#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool are_friend[4001][4001];
int degree[4001];

int main(){

    int n,m;
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        are_friend[a][b]=true;
        are_friend[b][a]=true;
        degree[a]++;
        degree[b]++;
    }

    int answ=-1;
    for(int a=1;a<=n;a++){
        for(int b=a+1;b<=n;b++){
            if(are_friend[a][b]){
                for(int c=b+1;c<=n;c++){
                    if(are_friend[a][c] && are_friend[b][c]){
                        int temp = degree[a]+degree[b]+degree[c]-6;
                        if(answ==-1 || answ>temp){
                            answ=temp;
                        }
                    }
                }
            }
        }
    }

    cout << answ << '\n';

    return 0;
}