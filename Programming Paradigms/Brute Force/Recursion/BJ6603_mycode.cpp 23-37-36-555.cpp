#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> numbers;
int used[50];
int answ[6];

void backtrack(int idx){
    if(idx==6){
        for(int k=0;k<6;k++){
            cout << answ[k] << ' ';
        }
        cout << '\n';
        return;
    }

    for(int k : numbers){
        if(!used[k] && answ[idx-1]<k){
            used[k]=true;
            answ[idx]=k;
            backtrack(idx+1);
            answ[idx]=0;
            used[k]=false;
        }
    }
}

int main(){

    int howmuch=0;
    cin >> howmuch;

    while(howmuch!=0){
        numbers.resize(howmuch);
        for(int k=0;k<howmuch;k++){
            cin >> numbers[k];
        }

        backtrack(0);

        cout << '\n';
        cin >> howmuch;
    }



    return 0;
}