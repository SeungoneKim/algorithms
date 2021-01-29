#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

int main(){

    int n;
    cin >> n;

    vector<int>arr(n);
    for(int k=0;k<n;k++){
        cin >> arr[k];
    }

    int cal=arr[0];
    for(int k=1;k<n;k++){
        cal ^= arr[k];
    }

    if(cal!=0){
        cout << "koosaga" << '\n';
    }
    else{
        cout << "cubelover" <<'\n';
    }

    return 0;
}