#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int num_of_words, row_size;
int list_of_num[1001];
int dp[1001][1001];

int go(int used_word, int used_row_blanks){
    if(used_word==num_of_words){
        return 0;
    }
    if(dp[used_word][used_row_blanks]!=-1){
        return dp[used_word][used_row_blanks];
    }
    int& answ = dp[used_word][used_row_blanks];

    int left_row_blanks= row_size-used_row_blanks+1;
    int cost = left_row_blanks*left_row_blanks;
    // case of going to next row
    answ= go(used_word+1,list_of_num[used_word]+1)+cost;
    if(used_row_blanks+list_of_num[used_word]<=row_size){
        int cur= go(used_word+1,list_of_num[used_word]+used_row_blanks+1);
        if(answ>cur)answ=cur;
    }
    return answ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num_of_words >> row_size;
    for(int i=0;i<num_of_words;i++){
        cin >> list_of_num[i];
    }
    memset(dp,-1,sizeof(dp));
    cout << go(1,list_of_num[0]+1) << '\n';

    return 0;
}