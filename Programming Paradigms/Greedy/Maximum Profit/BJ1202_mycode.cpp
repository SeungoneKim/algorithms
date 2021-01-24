#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<pair<int,int>> jewlery(300000); // {weight,price}
multiset<int>bag;
multiset<int>::iterator iter;

bool cmp_func(pair<int,int>p1, pair<int,int>p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second>p2.second;
}

int main(){

    int jewlery_num,bag_num;
    cin >> jewlery_num >> bag_num;

    jewlery.resize(jewlery_num);

    for(int k=0;k<jewlery_num;k++){
        int w,p;
        cin >> w >> p;
        jewlery[k]={w,p};
    }
    for(int k=0;k<bag_num;k++){
        int w;
        cin >> w;
        bag.insert(w);
    }

    sort(jewlery.begin(),jewlery.end(),cmp_func);

    long long answ=0;
    for(int k=0;k<jewlery_num;k++){
        auto it = bag.lower_bound(jewlery[k].first);
        if(it != bag.end()){
            answ += jewlery[k].second;
            bag.erase(it);
        }
    }

    cout << answ << '\n';

    return 0;
}