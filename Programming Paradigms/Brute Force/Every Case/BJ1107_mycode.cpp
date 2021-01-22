#include <iostream>

using namespace std;

bool broken[10];

int how_much_to_press(int num){
    if(num==0){
        if(broken[0]){
            return 0;
        }
        else{
            return 1;
        }
    }
    int len=0;
    while(num>0){
        if(broken[num%10]){
            return 0;
        }
        else{
            len++;
            num /= 10;
        }
    }
    return len;
}

int main(){
    int target;
    int broken_num;

    cin >> target;
    cin >> broken_num;
    for(int k=1;k<=broken_num;k++){
        int x;
        cin >> x;
        broken[x]=true;
    }

    int answ=target-100;
    if(answ<0) answ = -answ;

    for(int k=0;k<1000000;k++){
        int search_num=k;
        int len = how_much_to_press(search_num);
        if(len >0){
            int press_num = search_num-target;
            if(press_num<0) press_num = -press_num;
            if(answ>len+press_num) answ = len+press_num;
        }
    }

    cout << answ << '\n';

    return 0;
}