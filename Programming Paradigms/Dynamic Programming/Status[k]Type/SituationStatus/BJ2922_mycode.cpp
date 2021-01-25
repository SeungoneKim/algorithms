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

// Global arrays
string s;
long long way[3]={0,5,20};
long long dp[101][3][3][2];
// Global variables

// functions
int what(char x) {
    if (x == 'A' || x == 'E' || x == 'I' || x== 'O' || x=='U') {
        return 1;
    } else {
        return 2;
    }
}
long long go(int n, int lastlast, int last, int yesno){
    if(n==s.length()){
        if(yesno==1){
            return 1;
        }
        else
            return 0;
    }
    long long& answ=dp[n][lastlast][last][yesno];
    if(answ!=-1) return answ;
    answ=0;
    if(s[n]!='_'){
        if(lastlast==last && last==what(s[n])){
            return 0;
        }
        answ = go(n+1,last,what(s[n]),(yesno|(s[n]=='L')));
        return answ;
    }
    for(int k=1;k<3;k++){
        if(lastlast==last && last==k) continue;
        answ += way[k]*go(n+1,last,k,yesno);
    }
    if(lastlast==last && last==2){
        //empty
    }
    else{
        answ += go(n+1,last,2,1);
    }
    return answ;
}
// main function
int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    memset(dp,-1,sizeof(dp));
    cout << go(0,0,0,0) << '\n';

    return 0;
}