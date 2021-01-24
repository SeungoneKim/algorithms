#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int myPow(int x, int p)
{
  if (p == 0) return 1;
  if (p == 1) return x;

  int tmp = myPow(x, p/2);
  if (p%2 == 0) return tmp * tmp;
  else return x * tmp * tmp;
}

vector<int>letter_to_number(10);
string add_target[10];

int main(){

    for(int k=0;k<10;k++){
        letter_to_number[k]= k;
    }


    int add_target_num;
    cin >> add_target_num;

    for(int k=0;k<add_target_num;k++){
        cin >> add_target[k];
    }

    int answ=0;
    do{
        int tmp=0;
        for(int k=0;k<add_target_num;k++){
            int len=add_target[k].length();
            for(int t=0;t<len;t++){
                if(t==0){
                    if((add_target[k])[t]==0){
                        
                    }
                }
                tmp += letter_to_number[(add_target[k])[t]-'A'] * myPow(10,(len-t-1));
            }
        }
        if(tmp>answ){
             answ=tmp;
             /*
             for(int k=0;k<10;k++){
                cout << letter_to_number[k] << ' ';
             }
             cout << '\n';
            */
        }
        
    }while(next_permutation(letter_to_number.begin(),letter_to_number.end()));

    cout << answ << '\n';

    return 0;
}