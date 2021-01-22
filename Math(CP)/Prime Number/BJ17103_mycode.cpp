#include <iostream>
using namespace std;

int prime[1000001];
int pn;
bool check[1000001];
int answarr[101];

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int numoftc;
    cin >> numoftc;

    check[1] = true;
    for (int i = 2; i <= 1000000; i++) {
        if (check[i] == false) {
            prime[++pn] = i;
            for (int j = i + i; j <= 1000000; j += i) {
                check[j] = true;
            }
        }
    }

    for(int k=1;k<=numoftc;k++){
        int n;
        cin >> n;
        
        for (int i = 1; i <= pn; i++) {
            if(n-prime[i]>0){
                if (check[n - prime[i]] == false && prime[i]<=n-prime[i]) {
                    //cout << n << ' ' << prime[i] << ' ' << n-prime[i] << '\n';
                    answarr[k]++;
                }
            }
        }

        cout << answarr[k] << '\n';
    }
    return 0;
}