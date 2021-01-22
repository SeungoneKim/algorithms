#include <iostream>
#include <string>

using namespace std;

void add(int& target, int howmuch){
    target = target | (1<<howmuch);
}

void remove(int& target, int howmuch){
    target = target & ~(1<<howmuch);
}

int check(int& target, int howmuch){
    return target & (1<<howmuch);
}

void toggle(int& target, int howmuch){
    target = target ^ (1<<howmuch);
}

void all(int&target){
    target = (1<<21)-1;
}

void empty(int& target){
    target=0;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int calculation_number;
    cin >> calculation_number;

    int x=0;
    while(calculation_number--){
        string s;
        cin >> s;
        if(s=="add"){
            int k;
            cin >> k;
            add(x,k);
        }
        else if(s=="remove"){
            int k;
            cin >> k;
            remove(x,k);
        }
        else if(s=="check"){
            int k;
            cin >> k;
            if(check(x,k)>0){
                cout << 1 << '\n';
            }
            else
                cout << 0 << '\n';
        }
        else if(s=="toggle"){
            int k;
            cin >> k;
            toggle(x,k);
        }
        else if(s=="all"){
            all(x);
        }
        else{ // s=="empty"
            empty(x);
        }
    }

    return 0;
}