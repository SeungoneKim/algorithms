#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int an,bn;
    cin >> an >> bn;

    vector<int>a(an);
    vector<int>b(bn);
    vector<int>c(an+bn);

    for(int k=0;k<an;k++){
        cin >> a[k];
    }
    for(int k=0;k<bn;k++){
        cin >> b[k];
    }

    int aidx=0;
    int bidx=0;
    int cidx=0;
    while(aidx<an && bidx<bn){
        if(a[aidx]<b[bidx]){
            c[cidx++]=a[aidx++];
        }
        else{
            c[cidx++]=b[bidx++];
        }
    }
    if(aidx<an){
        while(aidx<an){
            c[cidx++]=a[aidx++];
        }
    }
    else{
        while(bidx<bn){
            c[cidx++]=b[bidx++];
        }
    }

    for(int k=0;k<an+bn;k++){
        cout << c[k] << ' ';
    }
    cout << '\n';

    return 0;
}