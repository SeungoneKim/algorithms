#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <deque>
#include <cstdlib>
#include <climits>

using namespace std;

int quest_num;
bool dp[1001][1001];
int leftover[1001][1001];
int STR[1001];
int INT[1001];
int PNT[1001];

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> quest_num;
    for(int i=1;i<=quest_num;i++){
        cin >> STR[i] >> INT[i] >> PNT[i];
    }

    int answ=0;
    for(int s=1;s<1001;s++){
        for(int i=1;i<1001;i++){

            int cnt=0;
            leftover[s][i] = 2-s-i;
            for(int t=1;t<=quest_num;t++){
                if( (STR[t]<=s) || (INT[t]<=i) ){
                    cnt++;
                    leftover[s][i] += PNT[t];
                }
            }

            if(s==1 && i==1){
                dp[s][i]=true;
            }
            else if( ((s-1)>=1) && (dp[s-1][i]==true) && (leftover[s-1][i]>0) ){
                dp[s][i]=true;
            }
            else if( ((i-1)>=1) && (dp[s][i-1]==true) && (leftover[s][i-1]>0) ){
                dp[s][i]=true;
            }
            if(dp[s][i]){
                answ=max(cnt,answ);
            }
        }
    }

    cout << answ << '\n';

    return 0;

}