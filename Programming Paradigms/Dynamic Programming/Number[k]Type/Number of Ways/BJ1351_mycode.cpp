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

map<long long,long long>m;

long long go(long long i,int& p,int& q){
    if(i==0){
        return 1;
    }
    if(m[i]!=0) return m[i];
    long long answ= go(i/p,p,q) + go(i/q,p,q);
    m[i]=answ;
    return answ;
}

int main(){

    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long n;
    int p,q;
    cin >> n >> p >> q;

    cout << go(n,p,q) << '\n';

    return 0;
}