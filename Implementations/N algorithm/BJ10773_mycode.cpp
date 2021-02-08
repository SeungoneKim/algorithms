#include <bits/stdc++.h>

using namespace std;

int answ=0;
vector<int> v;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int k;
    cin >> k;

    for(int i=0;i<k;i++){
        int tmp;
        cin >> tmp;

        if(tmp!=0){
            answ+= tmp;
            v.push_back(tmp);
        }
        else{
            tmp = *(v.end()-1);
            answ -= tmp;
            v.pop_back();
        }
    }

    cout << answ << '\n';

    return 0;
}