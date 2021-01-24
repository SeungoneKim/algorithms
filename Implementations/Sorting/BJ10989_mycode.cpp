#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num_list[10001];
vector<int> available;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    for(int k=0;k<num;k++){
        int x;
        cin >> x;
        num_list[x]++;
    }

    for(int k=1;k<10001;k++){
        if(num_list[k]>0)
            available.push_back(k);
    }

    sort(available.begin(),available.end());

    for(auto p: available){
        while(num_list[p]>0){
            cout << p << '\n';
            num_list[p]--;
        }
    }

    return 0;
}