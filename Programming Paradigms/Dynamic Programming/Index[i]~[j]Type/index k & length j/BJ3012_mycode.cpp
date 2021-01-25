#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

long long dp[201][201];

char open_parenthesis[3]={'(','{','['};
char closed_parenthesis[3]={')','}',']'};
int find_parenthesis(char c){
    int answ=-1;
    bool flg=false;
    for(int a=0;a<3;a++){
        if(open_parenthesis[a]==c){
            answ=a;
            flg=true;
        }
    }
    if(!flg){
        for(int a=0;a<3;a++){
            if(closed_parenthesis[a]==c){
                answ=a+3;
            }
        }
    }
    return answ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int len;
    cin >> len;
    string str;
    cin >> str;

    for(int s=0;s<=len-2;s++){
        if(str[s]=='?' && str[s+1]=='?'){
            dp[s][s+1]=3;
        }
        else if(str[s]=='?' || str[s+1]=='?'){
            if(str[s]=='?'){
                int k=find_parenthesis(str[s+1]);
                if(3<=k && k<=5){
                    dp[s][s+1]=1;
                }
            }
            else{
                int k=find_parenthesis(str[s]);
                if(0<=k && k<=2){
                    dp[s][s+1]=1;
                }
            }
        }
        else if(find_parenthesis(str[s])+3==find_parenthesis(str[s+1])){
            dp[s][s+1]=1;
        }
    }
    for(int k=1;k<=len;k++){
        dp[k][k-1]=1;
    }

    for(int k=4;k<=len;k+=2){
        for(int s=0;s<len-k+1;s++){
            int e= s+k-1;
            for(int j=s+1;j<=e;j+=2){
                
                if(str[s]=='?' && str[j]=='?'){
                    dp[s][e] += 3*dp[s+1][j-1]*dp[j+1][e];
                    dp[s][e]%=100000;
                }
                else if(str[s]=='?' || str[j]=='?'){
                    if(str[s]=='?'){
                        int k=find_parenthesis(str[j]);
                        if(3<=k && k<=5){
                            dp[s][e] += dp[s+1][j-1]*dp[j+1][e];
                            dp[s][e]%=100000;
                        }
                    }
                    else{
                        int k=find_parenthesis(str[s]);
                        if(0<=k && k<=2){
                            dp[s][e] += dp[s+1][j-1]*dp[j+1][e];
                            dp[s][e]%=100000;
                        }
                    }
                }
                else{
                    if(find_parenthesis(str[s])+3==find_parenthesis(str[j])){
                        dp[s][e] += dp[s+1][j-1]*dp[j+1][e];
                        dp[s][e]%=100000;
                    }
                }
            }
        }
    }
    
    string ans="";
    if(dp[0][len-1]%100000<10000){
        ans=to_string(dp[0][len-1]%100000);
        int stand= ans.length();
        while(stand<5){
            ans = "0"+ans;
            stand++;
        }
        cout << ans << '\n';
    }
    else{
        cout << dp[0][len-1]%100000 << '\n';
    }
    /*
    for(int s=0;s<=len-1;s++){
        for(int e=0;e<=len-1;e++){
            cout << dp[s][e] << ' ';
        }
        cout << '\n';
    }
    */
    return 0;
}