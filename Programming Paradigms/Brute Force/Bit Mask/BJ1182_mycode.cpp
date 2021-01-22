#include <iostream>
#include <vector>

using namespace std;

int main(){

    int vecsize, goal;
    cin >> vecsize >> goal;

    vector<int> numbers(vecsize);
    for(int k=0;k<vecsize;k++){
        cin >> numbers[k];
    }

    int answ=0;
    for(int k=1;k< (1<<vecsize)-1;k++){
        int sum=0;
        for(int t=0;t<vecsize;t++){
            if(k&(1<<t)){
                sum+=numbers[t];
            }
        }
        if(sum==goal) answ++;
    }    

    cout << answ << '\n';

    return 0;
}