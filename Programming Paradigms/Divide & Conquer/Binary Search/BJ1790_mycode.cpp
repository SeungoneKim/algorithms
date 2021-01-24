#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int myPow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

long long calculation(int n){
    string tmp=to_string(n);
    int len= tmp.length();

    long long answ=0;
    for(int k=1;k<len;k++){
        answ += k*9*myPow(10,k-1);
    }
    answ+= len*(n-myPow(10,len-1)+1);

    return answ;
}

int main(){

    int n,k;
    cin >> n >> k;

    if(calculation(n)<k){
        cout << -1 << '\n';
        return 0;
    }

    int left=1;
    int right=n;
    int ans=0;

    while(left<=right){
        int mid = (left+right)/2;
        long long sol = calculation(mid);

        if(sol<k){
            left = mid+1;
        }
        else{
            ans=mid;
            right= mid-1;
        }
    }

    string midstr = to_string(ans);
    long long l = calculation(ans);
    cout << midstr[midstr.length()-l+k-1] << '\n';

    return 0;
}