#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main(){

    int len;
    cin >> len;
    vector<int>numbers(len);
    for(int i=0;i<len;i++){
        cin >> numbers[i];
    }

    if(len==1){
        cout << 0 << '\n';
        return 0;
    }
    int answ=-1;
    for(int d1=-1;d1<=1;d1++){
        for(int d2=-1;d2<=1;d2++){
            int change=0;
            if(d1!=0) change++;
            if(d2!=0) change++;
            int a0=numbers[0]+d1;
            int diff=(numbers[1]+d2)-a0;
            bool ok=true;
            int an=a0+diff;
            for(int k=2;k<len;k++){
                an += diff;
                if(numbers[k]==an)continue;
                if(numbers[k]-1==an) change++;
                else if(numbers[k]+1==an) change++;
                else{
                    ok=false;
                    break;
                }
            }
            if(ok){
                if(answ==-1 || answ>change){
                    answ=change;
                }
            }
        }
    }

    cout << answ << '\n';

    return 0;
}