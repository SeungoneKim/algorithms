#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> leng(9);
vector<int> resu(7);
bool isit[9];

int main(){

    int total=0;
    for(int k=0;k<9;k++){
        cin >> leng[k];
        total += leng[k];
        isit[k]=true;
    }

    bool flg=false;
    for(int k=0;k<8;k++){
        for(int t=k+1;t<9;t++){
            int cons=leng[k]+leng[t];
            if(total-cons==100){
                isit[k]=false;
                isit[t]=false;
                flg=true;
                break;
            }
        }
        if(flg==true)
            break;
    }

    int t=0;
    for(int k=0;k<9;k++){
        if(isit[k]==true){
            resu[t]=leng[k];
            t++;
        }
    }

    sort(resu.begin(),resu.end());

    for(int k=0;k<7;k++){
        cout << resu[k] << '\n';
    }

    return 0;
}