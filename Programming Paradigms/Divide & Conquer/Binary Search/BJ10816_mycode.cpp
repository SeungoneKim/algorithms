#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int>cards(n);
    for(int k=0;k<n;k++){
        cin >> cards[k];
    }
    sort(cards.begin(),cards.end());

    int m;
    cin >> m;

    vector<int>queries(m);
    for(int k=0;k<m;k++){
        cin >> queries[k];
    }

    vector<int>::iterator up;
    vector<int>::iterator down;

    for(int k=0;k<m;k++){
        int num=queries[k];
        cout << upper_bound(cards.begin(),cards.end(),num)-lower_bound(cards.begin(),cards.end(),num) << ' ';
    }
    cout << '\n';

    return 0;
}