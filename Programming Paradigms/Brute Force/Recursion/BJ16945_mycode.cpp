#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <tuple>

using namespace std;

bool is_magic(vector<int> &d){
    int magic = d[0]+d[1]+d[2];
    for(int i=0;i<3;i++){
        int sum=0;
        for(int j=0;j<3;j++){
            sum += d[3*i+j];
        }
        if(magic != sum) return false;
    }
    for(int j=0;j<3;j++){
        int sum=0;
        for(int i=0;i<3;i++){
            sum += d[3*i+j];
        }
        if(magic != sum) return false;
    }
    if(magic != d[0]+d[4]+d[8]) return false;
    if(magic != d[2]+d[4]+d[6]) return false;
    return true;
}

int diff(vector<int>& a, vector<int>& d){
    int answ=0;
    for(int i=0;i<9;i++){
        int temp = abs(a[i]-d[i]);
        answ += temp;
    }
    return answ;
}

int main(){

    vector<int>a(9);
    for(int i=0;i<9;i++){
        cin >> a[i];
    }
    vector<int>d(9);
    for(int i=0;i<9;i++){
        d[i]=i+1;
    }
    int answ=-1;
    do{
        if(is_magic(d)){
            int cost=diff(a,d);
            if(answ==-1 || answ>cost){
                answ=cost;
            }
        }
    }while(next_permutation(d.begin(),d.end()));

    cout << answ << '\n';

    return 0;
}