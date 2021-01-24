#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[10000];
int arrsize;

int calculation(int m){
    int t1= arr[0];
    int t2= arr[0];
    int answ=1;
    for(int k=1;k<arrsize;k++){
        if(arr[k]<t1){
            t1=arr[k];
        }
        if(arr[k]>t2){
            t2=arr[k];
        }
        if(t2-t1>m){
            answ++;
            t1=arr[k];
            t2=arr[k];
        }
    }
    return answ;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max_of_section_score;
    cin >> arrsize >> max_of_section_score;

    int left = 0;
    int right = 0;
    for(int k=0;k<arrsize;k++){
        cin >> arr[k];
        if(arr[k]>right) right=arr[k];
    }
    
    int mid = 0;
    int answ=right;
    while(left<=right){
        mid= (left) + (right-left)/2;
        int sol = calculation(mid);
        if(sol <= max_of_section_score){
            if(answ>mid) answ=mid;
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    cout << answ << '\n';

    return 0;
}