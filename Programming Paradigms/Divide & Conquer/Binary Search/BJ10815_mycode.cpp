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
    vector<int>yesno(m);
    for(int k=0;k<m;k++){
        cin >> yesno[k];
    }

    for(int k=0;k<m;k++){
        int left=0;
        int right=n-1;
        int mid=0;
        bool flg=false;
        while(left<=right){
            mid= left+(right-left)/2;
            // cout << mid << ' ' << cards[mid] << ' ' << '\n';
            if(yesno[k]==cards[mid]){
                flg=true;
                cout << 1 << ' ';
                break;
            }
            else if(yesno[k]<cards[mid]){
                right=mid-1;
            }
            else{
                left=mid+1;
            }
        }
        if(!flg){
            cout << 0 << ' ';
        }
    }
    cout << '\n';

    return 0;
}