#include <iostream>

using namespace std;

int prime[1000001];
int pn=0;
bool check[1000001];

int main(){

    int s,e;
    cin >> s >> e;

    for(int k=2;k<=e;k++){
        if(check[k]==false){
            if(k>=s){
                prime[pn++]=k;
            }
            for(int i=k*2;i<=e;i+=k){ 
                check[i] = true;
            }
        }
    }

    for(int k=0;k<pn;k++){
        cout << prime[k] << '\n';
    }

    return 0;
}