#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int cur_status[131];

int main(){

    int len,which;
    cin>> len >> which;

    for(int i=1;i<=len;i++){
        cin >> cur_status[i];
    }

    int answ=0;
    for(int k=1;k<=len;k++){
        switch(which){
            case 1:
                answ++;
                if(k+3<=len){
                    if(cur_status[k]==cur_status[k+1] && cur_status[k+1]==cur_status[k+2] && cur_status[k+2]==cur_status[k+3]){
                        answ++;
                    }
                }
                break;
            case 2:
                if(k+1<=len){
                    if(cur_status[k]==cur_status[k+1]){
                        answ++;
                    }
                }
                break;
            case 3:
                if(k+2<=len){
                    if(cur_status[k]==cur_status[k+1] && cur_status[k+1]+1==cur_status[k+2]){
                        answ++;
                    }
                }
                if(k+1<=len){
                    if(cur_status[k]==cur_status[k+1]+1){
                        answ++;
                    }
                }
                break;
            case 4:
                if(k+2<=len){
                    if(cur_status[k]==cur_status[k+1]+1 && cur_status[k+1]==cur_status[k+2]){
                        answ++;
                    }
                }
                if(k+1<=len){
                    if(cur_status[k]+1==cur_status[k+1]){
                        answ++;
                    }
                }
                break;
            case 5:
                if(k+2<=len){
                    if(cur_status[k]==cur_status[k+1] && cur_status[k+1]==cur_status[k+2]){
                        answ++;
                        
                    }
                    if(cur_status[k]==cur_status[k+1]+1 && cur_status[k+1]+1==cur_status[k+2]){
                        answ++;
                        
                    }
                }
                if(k+1<=len){
                    if(cur_status[k]+1==cur_status[k+1]){
                        answ++;
                        
                    }
                    if(cur_status[k]==cur_status[k+1]+1){
                        answ++;
                        
                    }
                }
                break;
            case 6:
                if(k+2<=len){
                    if(cur_status[k]==cur_status[k+1] && cur_status[k+1]==cur_status[k+2]){
                        answ++;
                    }
                    if(cur_status[k]+1==cur_status[k+1] && cur_status[k+1]==cur_status[k+2]){
                        answ++;
                    }
                }
                if(k+1<=len){
                    if(cur_status[k]==cur_status[k+1]){
                        answ++;
                    }
                    if(cur_status[k]==cur_status[k+1]+2){
                        answ++;
                    }
                }
                break;
            case 7:
                if(k+2<=len){
                    if(cur_status[k]==cur_status[k+1] && cur_status[k+1]==cur_status[k+2]){
                        answ++;
                    }
                    if(cur_status[k]==cur_status[k+1] && cur_status[k+1]==cur_status[k+2]+1){
                        answ++;
                    }
                }
                if(k+1<=len){
                    if(cur_status[k]==cur_status[k+1]){
                        answ++;
                    }
                    if(cur_status[k]+2==cur_status[k+1]){
                        answ++;
                    }
                }
                break;

            
        }
    }

    cout << answ << '\n';

    return 0;
}