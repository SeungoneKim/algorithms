#include <iostream>

using namespace std;

int myPow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

int main(){

    int num;
    cin >> num;

    int len=0;
    int n = num;
    while(n>0){
        n /= 10;
        len++;
    }
    
    int to_consider = num - myPow(10,len-1)+1;

    int answ=0;
    for(int k=1;k<=len-1;k++){
        answ += 9*myPow(10,k-1) * k;
    }

    answ += to_consider * len;

    cout << answ << '\n';

    return 0;
}