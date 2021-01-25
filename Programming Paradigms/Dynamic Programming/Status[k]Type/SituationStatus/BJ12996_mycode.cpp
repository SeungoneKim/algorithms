#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

long long dp[51][51][51][51];

int dx[7]={1,1,1,1,0,0,0};
int dy[7]={0,0,1,1,0,1,1};
int dz[7]={1,0,1,0,1,1,0};

long long dynamic(int l, int x, int y, int z){
    if(l==0){
        if(x==0 && y==0 && z==0){
            return 1;
        }
        else{
            return 0;
        }
    }
    if(x<0 || y<0 || z<0) return 0;
    if(dp[l][x][y][z]!=-1) return dp[l][x][y][z];

    dp[l][x][y][z]=0;
    for(int u=0;u<7;u++){
        dp[l][x][y][z] += dynamic(l-1,x-dx[u],y-dy[u],z-dz[u]);
    }
    dp[l][x][y][z] %= 1000000007;
    return dp[l][x][y][z];
}

int main(){

    int num_of_song,a,b,c;
    cin >> num_of_song >> a >> b >> c;

    memset(dp,-1,sizeof(dp));

    cout << dynamic(num_of_song,a,b,c) << '\n';

    return 0;
}