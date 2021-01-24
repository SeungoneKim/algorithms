#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int number_of_operands[4]; // 0 is +, 1 is -, 2 is *, 3 is /

int main(){

    int len;
    cin >> len;

    vector<int>numbers(len);
    for(int k=0;k<len;k++){
        cin >> numbers[k];
    }

    for(int k=0;k<4;k++){
        cin >> number_of_operands[k];
    }
    
    vector<int>tmp;
    for(int k=0;k<number_of_operands[0];k++){
        tmp.push_back(0);
    }
    for(int k=0;k<number_of_operands[1];k++){
        tmp.push_back(1);
    }
    for(int k=0;k<number_of_operands[2];k++){
        tmp.push_back(2);
    }
    for(int k=0;k<number_of_operands[3];k++){
        tmp.push_back(3);
    }

    int maxansw=-100000000;
    int minansw=1000000000;
    do{
        int calc=numbers[0];
        for(int k=0;k<len-1;k++){
            int ch=tmp[k];
            if(ch==0){
                calc+= numbers[k+1];
            }
            else if(ch==1){
                calc-= numbers[k+1];
            }
            else if(ch==2){
                calc*= numbers[k+1];
            }
            else{
                calc/= numbers[k+1];
            }
        }
        if(calc>maxansw){
            maxansw=calc;
            /*
            cout << "This is max" << '\n';
            for(int k=0;k<len-1;k++){
                cout << tmp[k] << ' ';
            }
            cout << '\n';
            */
        }
        if(calc<minansw){
            minansw=calc;
            /*
            cout << "This is min" << '\n';
            for(int k=0;k<len-1;k++){
                cout << tmp[k] << ' ';
            }
            cout << '\n';
            */
        }
    }while(next_permutation(tmp.begin(),tmp.end()));

    cout << maxansw << '\n';
    cout << minansw << '\n';

    return 0;
}