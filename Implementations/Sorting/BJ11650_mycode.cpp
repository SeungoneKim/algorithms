#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

vector<pair<int,int>> v;

bool compare(pair<int,int> t1, pair<int, int> t2){
    if(t1.first == t2.first){
        return t1.second < t2.second;
    }
    else{
        return t1.first < t2.first;
    }
}


int main(){
    
    int size;
    scanf("%d",&size);
    
    for(int i=0;i<size;i++){
        pair<int, int> tmp;
        scanf("%d %d",&tmp.first, &tmp.second);
        v.push_back(tmp);
    }
    
    //sorting
    sort(v.begin(),v.end(), compare);
    
    for(int i=0;i<size;i++){
        printf("%d %d\n",v[i].first, v[i].second);
    }
    
    return 0;
}