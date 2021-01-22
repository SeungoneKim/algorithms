#include <iostream>
#include <algorithm>

using namespace std;

long long factorial_calculate(long long num, long long divide){
    long long answ=0;
    long long init_divide = divide;

     while(true){
        if(num>=divide){
            answ += num/divide;
            divide *= init_divide;
        }
        else{
            return answ;
        }
    }

    return answ;
}

int main(){

    long long n,m;
    cin >> n >> m;

    long long n2 = factorial_calculate(n, 2);
    long long n5 = factorial_calculate(n, 5);
    long long m2 = factorial_calculate(m, 2);
    long long m5 = factorial_calculate(m, 5);
    long long n_m2 = factorial_calculate(n-m,2);
    long long n_m5 = factorial_calculate(n-m,5);

    // cout << n2 << ' ' << n5 << ' ' << m2 << ' ' << m5 << ' ' << n_m2 << ' ' << n_m5 <<'\n';
    
    long long bot2 = m2+n_m2;
    long long bot5 = m5+n_m5;

    long long answ = min(n2-bot2,n5-bot5);

    cout << answ << '\n';

    return 0;
}