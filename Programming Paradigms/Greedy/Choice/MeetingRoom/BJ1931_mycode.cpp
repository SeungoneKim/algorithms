#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp_func(pair<int,int>p1, pair<int,int>p2){
    if(p1.second<p2.second){
        return true;
    }
    else if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return false;
}

int main(){

    int meeting;
    cin >> meeting;

    vector<pair<int,int>> meeting_list(meeting);
    for(int k=0;k<meeting;k++){
        cin >> meeting_list[k].first >> meeting_list[k].second;
    }

    sort(meeting_list.begin(),meeting_list.end(),cmp_func);

    int now=0;
    int answ=0;
    for(int k=0;k<meeting;k++){
        if(now<=meeting_list[k].first){
            answ++;
            now = meeting_list[k].second;
        }
    }

    cout << answ << '\n';

    return 0;
}