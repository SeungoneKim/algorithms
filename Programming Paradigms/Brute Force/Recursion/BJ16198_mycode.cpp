#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int recursion(vector<int>&a){
    int n= a.size();
    if(n==2) return 0;
    int ans=0;
    for(int i=1;i<n-1;i++){
        int cur_energy= a[i-1]*a[i+1];
        vector<int>b(a);
        b.erase(b.begin()+i);
        cur_energy += recursion(b);
        if(ans<cur_energy){
            ans=cur_energy;
        }
    }
    return ans;
}

int main(){

    int n;
    cin >> n;

    vector<int> weight(n);
    for(int k=0;k<n;k++){
        cin >> weight[k];
    }

    cout << recursion(weight) << '\n';

    return 0;
}