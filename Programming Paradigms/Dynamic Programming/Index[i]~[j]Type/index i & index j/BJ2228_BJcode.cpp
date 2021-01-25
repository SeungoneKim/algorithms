#include <iostream>

using namespace std;

int arr[101];
bool visited[101][101];
int dp[101][101];

int minimum = -32768*101;

int dynamic(int section, int target_index){
    if(section == 0) return 0;
    if(target_index<0) return minimum;
    if(visited[section][target_index]) return dp[section][target_index];
    
    visited[section][target_index] = true;
    int& answ = dp[section][target_index];
    
    // not including target index in the section
    answ = dynamic(section, target_index-1);
    
    // including target index in the section
    int sum=0;
    for(int j=target_index;j>=1;j--){
        sum += arr[j];
        int tmp = dynamic(section-1, j-2)+sum;
        if(answ < tmp) answ = tmp;
    }
    return answ;
}


int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    // getting input
    int size, sec_num;
    cin >> size >> sec_num;
    
    for(int k=1;k<=size;k++){
        cin >> arr[k];
    }
    
    // dynamic programming
    int aws = dynamic(sec_num,size);
    
    // printing output
    cout << aws << '\n';
        
    return 0;
}