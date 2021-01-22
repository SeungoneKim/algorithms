#include <iostream>

using namespace std;

int MAXN = 1000000;
int prime[1000001]; //소수를 저장해놓는 배열
int pn=0;
bool check[1000001]; // 소수가 아니면 true

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    for(int k=2;k<=MAXN;k++){
        if(check[k]==false){
            prime[pn++]=k;

            for(int i=k*2;i<=MAXN;i+=k){ // k*k대신 k*2부터 하는 것이 좋다(arithmetic overflow)
                check[i] = true;
            }
        }
    }

    while(true){
        int a;
        cin >> a;

        if(a==0) break;

        for(int k=1;k<pn;k++){
            if(prime[k]<a){
                if(check[a-prime[k]]==false){
                    cout << a << " = " << prime[k] << " + " << a - prime[k] << '\n';
                    break;
                }
            }
        }
    }

    return 0;
}