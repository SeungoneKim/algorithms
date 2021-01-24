#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> list_of_num;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num;
    cin >> num;

    int size_of_num=0;
    vector<int>::iterator it;
    for(int k=0;k<num;k++){
        int tmp=0;
        cin >> tmp;
        it = lower_bound(list_of_num.begin(),list_of_num.end(),tmp);

        if(it!=list_of_num.end()){
            *it = tmp;
        }
        else{
            list_of_num.push_back(tmp);
        }
    }

    cout << list_of_num.size() << '\n';

    return 0;
}