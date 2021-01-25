#include <cstdio>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int n;
int a[10000];
int b[10000];
int dp[10000][10];

int go(int idx, int turn){
    if(idx==n){
        return 0;
    }
    if(dp[idx][turn]!=-1){
        return dp[idx][turn];
    }
    int cur= (a[idx]+turn)%10;

    int cost_left= (b[idx]-cur+10)%10;
    int left= cost_left+go(idx+1,(turn+cost_left)%10);

    int cost_right= (cur-b[idx]+10)%10;
    int right= cost_right+go(idx+1,turn);

    if(left<right){
        dp[idx][turn]=left;
    }
    else{
        dp[idx][turn]=right;
    }
    return dp[idx][turn];
}

int main(){

    scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%1d", &a[i]);
	}
	for (int i = 0; i < n; i++) {
		scanf("%1d", &b[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 10; j++) {
			dp[i][j] = -1;
		}
	}
	printf("%d\n", go(0, 0));

    return 0;
}