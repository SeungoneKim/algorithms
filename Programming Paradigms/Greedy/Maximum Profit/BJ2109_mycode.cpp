#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<pair<int,int>>list_of_classes(10000);

bool cmp_func(pair<int,int>p1,pair<int,int>p2){
    if(p1.second==p2.second){
        return p1.first>p2.first;
    }
    return p1.second>p2.second;
}

int main(){

    int num;
    cin >> num;

    list_of_classes.resize(num);

    for(int k=0;k<num;k++){
        int p, d;
        cin >> p >> d;
        list_of_classes[k].first=p;
        list_of_classes[k].second=d;
    }

    sort(list_of_classes.begin(),list_of_classes.end(),cmp_func);

    priority_queue<int>q;
    int stand=0;
    int answ=0;
    for(int k=10000;k>=1;k--){
        while(stand<num && list_of_classes[stand].second==k){
            q.push(list_of_classes[stand].first);
            stand++;
        }
        if(!q.empty()){
            answ+=q.top();
            q.pop();
        }
    }

    cout << answ << '\n';

    return 0;
}