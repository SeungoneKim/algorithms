#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

long long dp[7][1<<7];

int digit_num_count(int state){
    int answ=0;
    for(int i=0;i<7;i++){
        if((state&(1<<i))>0){
            answ++;
        }
    }
    return answ;
}

vector<int> transfer(int state){
    vector<int>answ;
    for(int i=0;i<7;i++){
        if((state&(1<<i))>0){
            answ.push_back(i);
        }
    }
    return answ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int rownum;
    while(cin >> rownum){
        vector<int>a(rownum);
        for(int i=0;i<rownum;i++){
            cin >> a[i];
        }
        int q=a[0];
        vector<int>b(q);
        for(int i=0;i<rownum;i++){
            for(int j=0;j<a[i];j++){
                b[j]++;
            }
        }
        int n;
        cin >> n;
        
        memset(dp,0,sizeof(dp));

        // initialization
        for(int i=0;i<(1<<n);i++){
            if(digit_num_count(i)==b[0]){
                dp[0][i]=1;
            }
        }

        // dynamic programming
        for(int i=1;i<q;i++){
            for(int s=0;s<(1<<n);s++){
                if(digit_num_count(s)!=b[i]) continue;
                for(int ps=0;ps<(1<<n);ps++){
                    if(digit_num_count(ps)!=b[i-1]) continue;
                    vector<int>before = transfer(ps);
                    vector<int>after = transfer(s);
                    bool flg=false;
                    for(int t=0;t<after.size();t++){
                        if(before[t]>after[t]){
                            flg=true;
                            break;
                        }
                    }
                    if(!flg){
                        dp[i][s] += dp[i-1][ps];
                    }
                }
            }
        }

        long long answ=0;
        for(int i=0;i<(1<<n);i++){
            if(digit_num_count(i)==b[q-1]){
                answ += dp[q-1][i];
            }
        }

        cout << answ << '\n';
    }

    return 0;
}