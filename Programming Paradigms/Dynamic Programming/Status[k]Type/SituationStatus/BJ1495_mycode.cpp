#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int songs[101];
bool dp[101][1001];

int main(){

    int num_songs,startvol,maxvol;
    cin >> num_songs >> startvol >> maxvol;

    for(int k=1;k<=num_songs;k++){
        cin >> songs[k];
    }

    dp[0][startvol]=true;
    for(int k=1;k<=num_songs;k++){
        for(int j=0;j<=maxvol;j++){
            if(dp[k-1][j]==true){
                if(0<=j+songs[k] && songs[k]+j<=maxvol){
                    dp[k][j+songs[k]]=true;
                }
                if(0<=j-songs[k] && j-songs[k]<=maxvol){
                    dp[k][j-songs[k]]=true;
                }
            }
        }
    }

    bool flg=false;
    for(int k=maxvol;k>=0;k--){
        if(dp[num_songs][k]==true){
            cout << k << '\n';
            flg=true;
            break;
        }
    }
    if(!flg){
        cout << -1 << '\n';
    }

    return 0;
}