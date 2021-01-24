#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<char> available(15);
vector<char> printer(15);
bool used[15];

char vowel[5]={'a','e','i','o','u'};

bool IsThisVowel(char test){
    for(int k=0;k<5;k++){
        if(test == vowel[k])
            return true;
    }
    return false;
}

void backtrack(int index, int len, int avail, int vowel, int con){

    if(index==len){
        if(vowel>=1 && con>=2){
            for(int k=0;k<len;k++){
                cout << printer[k];
            }
            cout << '\n';
        }
        return;
    }

    for(int k=0;k<avail;k++){
        if(!used[k]){
            if(index==0){
                bool isthisvow = IsThisVowel(available[k]);
                if(isthisvow){
                    used[k]=true;
                    printer[index]=available[k];
                    backtrack(index+1,len,avail,vowel+1,con);
                    used[k]=false;
                }
                else{
                    used[k]=true;
                    printer[index]=available[k];
                    backtrack(index+1,len,avail,vowel,con+1);
                    used[k]=false;
                }
            }
            else{
                if(printer[index-1]<available[k]){
                    bool isthisvow = IsThisVowel(available[k]);
                    if(isthisvow){
                        used[k]=true;
                        printer[index]=available[k];
                        backtrack(index+1,len,avail,vowel+1,con);
                        used[k]=false;
                    }
                    else{
                        used[k]=true;
                        printer[index]=available[k];
                        backtrack(index+1,len,avail,vowel,con+1);
                        used[k]=false;
                    }
                }
            }
        }
    }
    return;
}

int main(){

    int len,avail;
    cin >> len >> avail;

    available.resize(avail);

    for(int k=0;k<avail;k++){
        cin >> available[k];
    }
    sort(available.begin(),available.end());

    printer.resize(len);

    backtrack(0,len,avail,0,0);

    return 0;
}