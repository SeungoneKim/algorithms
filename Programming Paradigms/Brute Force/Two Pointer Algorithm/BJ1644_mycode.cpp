#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

vector<int>prime; //소수를 저장해놓는 배열
int pn=0;
bool check[4000001]; // 소수가 아니면 true

int main(){

    for(int k=2;k<=4000000;k++){
        if(check[k]==false){
            prime.push_back(k);
            pn++;

            for(int i=k*2;i<=4000000;i+=k){ // k*k대신 k*2부터 하는 것이 좋다(arithmetic overflow)
                check[i] = true;
            }
        }
    }

    int m;
    cin >> m;

    int left=0,right=0,sum=prime[0],answ=0;
    while(right<pn){
        if(sum<m){
            right++;
            sum += prime[right];
        }
        else if(sum==m){
            answ++;
            right++;
            sum += prime[right];
        }
        else if(sum>m){
            if(left==right){
                right++;
                sum += prime[right];
            }
            else{
                sum -= prime[left];
                left++;
            }
        }
    }

    cout << answ << '\n';

    return 0;
}