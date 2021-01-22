#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    int parenthesis_num;
    cin >> parenthesis_num;

    int letter_num=parenthesis_num+1;
    
    vector<char>parenthesis(parenthesis_num);
    for(int k=0;k<parenthesis_num;k++){
        cin >> parenthesis[k];
    }

    vector<int> tmp(10);
    for(int k=0;k<10;k++){
        tmp[k]=k;
    }

    vector<int> maxansw(10);
    vector<int> minansw(10);
    for(int k=0;k<10;k++){
        maxansw[k]=k;
        minansw[k]=k;
    }

    int idx=0;
    do{
        bool flg=false;
        for(int t=0;t<parenthesis_num;t++){
            if(parenthesis[t]=='<'){
                if(tmp[t]>tmp[t+1]){
                    flg=true;
                }
            }
            else{
                if(tmp[t]<tmp[t+1]){
                    flg=true;
                }
            }
        }
        if(!flg){
            if(idx==0){
                minansw=tmp;
            }
            idx++;
            maxansw=tmp;
        }
    }while(next_permutation(tmp.begin(),tmp.end()));

    for(int k=0;k<letter_num;k++){
        cout << maxansw[k];
    }
    cout << '\n';
    for(int k=0;k<letter_num;k++){
        cout << minansw[k];
    }
    cout << '\n';

    return 0;
}