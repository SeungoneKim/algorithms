#include <iostream>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

bool cmpfunc(pair<int,int>p1,pair<int,int>p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second>p2.second;
}

int main(){

    // 비교함수를 바꾸는 것은 순차컨테이너에서 sort를 할 때, 기본 오름차순 대신 내림차순으로 정렬하거나, 다른 방식으로 비교가 이루어지기 원할 때이다.
    pair<int,int>a1={2,4};
    pair<int,int>a2={3,4};
    pair<int,int>a3={1,10};

    vector<pair<int,int>>v;
    v.push_back(a1);
    v.push_back(a2);
    v.push_back(a3);

    sort(v.begin(),v.end(),cmpfunc);

    for(auto& ele : v){
        cout << ele.first << ' ' << ele.second << '\n';
    }

    return 0;
}