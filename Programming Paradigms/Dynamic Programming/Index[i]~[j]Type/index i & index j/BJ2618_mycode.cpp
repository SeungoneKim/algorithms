#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int cases_num;

vector<pair<int,int>>cases;
int dp[1003][1003];
vector<int>answer;
int infinity=100000000;

int distance(int r1,int r2,int c1,int c2){
    int answ= abs(r1-r2) + abs(c1-c2);

    return answ;
}

int go(int idx,int police1,int police2){
    if(idx>cases_num){
        return 0;
    }
    int& answ= dp[police1][police2];
    if(answ>0) return answ;

    answ = go(idx+1,idx,police2)+ distance(cases[police1].first,cases[idx].first,cases[police1].second,cases[idx].second);
    int tmp=1;
    int next=go(idx+1,police1,idx)+ distance(cases[police2].first,cases[idx].first,cases[police2].second,cases[idx].second);
    if(answ>next){
        answ=next;
        tmp=2;
    }
    answer.push_back(tmp);

    return answ;
}

int main(){

    int matrix_size;
    cin >> matrix_size;

    cin >> cases_num;
    cases.push_back({0,0});
    for(int t=0;t<cases_num;t++){
        int a,b;
        cin >> a >> b;
        cases.push_back({a,b});
    }
    cases.push_back({matrix_size,matrix_size});

    int answ=go(1,0,cases_num+1);

    cout << dp[0][cases_num+1] << '\n';
    for(int& a : answer){
        cout << a << '\n';
    }

    for(int k=0;k<=cases_num+1;k++){
        for(int t=0;t<=cases_num+1;t++){
            cout << dp[k][t] << ' ';
        }
        cout << '\n';
    }
    return 0;
}