#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<char>string_list(51);

int main(){

    int length, answer;
    cin >> length >> answer;

    string_list.resize(length+1);

    int num_of_b=0;
    bool flg=false;
    for(int i=length;i>=0;i--){
        if(i*(length-i)>=answer){
            flg=true;
            num_of_b=i;
            
            // area1
            int num_of_area1= answer/i;
            if(num_of_area1>0){
                for(int k=1;k<=num_of_area1;k++){
                    string_list[k]='A';
                    answer -= i;
                }
            }
            
            // in area2, only maximum of 1 'A' can come between the 'B's.
            bool area2_exist=false;
            if(answer>0){
                area2_exist=true;
                int idx_of_area2= 1+num_of_area1+(num_of_b-answer);
                for(int k=num_of_area1+1;k<=num_of_area1+num_of_b+1;k++){
                    if(k!=idx_of_area2){
                        string_list[k]='B';
                    }
                    else{
                        string_list[k]='A';
                    }
                }
            }
            else{
                for(int k=num_of_area1+1;k<=num_of_area1+num_of_b;k++){
                    string_list[k]='B';
                }
            }
            
            // area3
            int start_of_area3= area2_exist?num_of_area1+num_of_b+2:num_of_area1+num_of_b+1;
            if(answer==0 && start_of_area3<length){
                for(int k=start_of_area3;k<=length;k++){
                    string_list[k]='A';
                }
            }
            break;
        }
    }

    if(flg==false){
        cout << -1 << '\n';
        return 0;
    }

    for(int k=1;k<=length;k++){
        cout << string_list[k];
    }
    cout << '\n';

    return 0;
}