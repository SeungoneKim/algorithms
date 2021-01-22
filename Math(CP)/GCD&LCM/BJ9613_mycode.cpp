#include <iostream>

using namespace std;

int gcd(int s, int b){
    if(s==0) return b;

    int k =s;
    s= b%s;
    b=k;

    return gcd(s,b);
}

int main(){
    int tc;
    cin >> tc;

    while(tc--){
        int arr[101];
        int num;
        cin >> num;

        for(int k=0;k<num;k++){
            cin >> arr[k];
        }

        long long answ =0;
        for(int k=0;k<num-1;k++){
            for(int t=k+1;t<num;t++){
                answ += gcd(arr[k],arr[t]);
            }
        }

        cout << answ << '\n';
    }

    return 0;
}