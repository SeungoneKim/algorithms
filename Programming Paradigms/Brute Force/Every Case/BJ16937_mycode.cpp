#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int main(){

    int height,width;
    cin >> height >> width;

    int sticker_num;
    cin >> sticker_num;

    vector<pair<int,int>> sticker(sticker_num);
    for(int k=0;k<sticker_num;k++){
        cin >> sticker[k].first >> sticker[k].second;
    }

    int answ=0;
    for(int i=0;i<sticker_num;i++){
        int r1=sticker[i].first;
        int c1=sticker[i].second;
        for(int j=i+1;j<sticker_num;j++){
            int r2=sticker[j].first;
            int c2=sticker[j].second;
            for(int rot1=0;rot1<2;rot1++){
                for(int rot2=0;rot2<2;rot2++){
                    if(r1+r2<=height && max(c1,c2)<=width){
                        int temp= r1*c1 + r2*c2;
                        if(answ<temp) answ=temp;
                    }
                    if(max(r1,r2)<=height && c1+c2<=width){
                        int temp= r1*c1 + r2*c2;
                        if(answ<temp) answ=temp;
                    }
                    swap(r2,c2);
                }
                swap(r1,c1);    
            }
        }
    }

    cout << answ << '\n';


    return 0;
}