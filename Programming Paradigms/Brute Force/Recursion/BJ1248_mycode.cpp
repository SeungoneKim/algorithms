#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int num;
//bool used[21]; // -10 into 0, need to plus 10.
int matrix[11][11]; // - ->-1, + ->1.
int answ[11];
int sum[11][11];

bool printed=false;

void backtrack(int len, int index){
    if(index==len){
        for(int k=1;k<index;k++){
            cout << answ[k] << ' ';
        }
        cout << '\n';
        printed=true;
        return;
    }
    for(int k=-10;k<=10;k++){
        bool flg=false;
        for(int t=1;t<=index;t++){
            /*
            if(used[k]){
                flg=true;
                break;
            }
            */
            if(matrix[t][index]>0){
                if(t==index && k<=0){
                    flg=true;
                    break;
                }
                else if(t!=index && sum[t][index-1]+k<=0){
                    flg=true;
                    break;
                }
            }
            else if(matrix[t][index]<0){
                if(t==index && k>=0){
                    flg=true;
                    break;
                }
                else if(t!=index && sum[t][index-1]+k>=0){
                    flg=true;
                    break;
                }
            }
            else{ // matrix[t][index]==0
                if(t==index && k!=0){
                    flg=true;
                    break;
                }
                else if(t!=index && sum[t][index-1]+k!=0){
                    flg=true;
                    break;
                }
            }
        }
        if(flg==true){
            continue;
        }
        else{
            //used[k]=true;
            answ[index]=k;
            for(int p=1;p<index;p++){
                sum[p][index]=sum[p][index-1]+k;
            }
            sum[index][index]=k;
            backtrack(len,index+1);
            if(printed==true){
                return;
            }
            sum[index][index]=0;
            for(int p=1;p<index;p++){
                sum[p][index]=0;
            }
            answ[index]=0;
            //used[k]=false;
        }
    }
    return;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> num;
    for(int k=1;k<=num;k++){
        for(int t=k;t<=num;t++){
            char x;
            cin >> x;
            if(x=='-'){
                matrix[k][t]=-1;
            }
            else if(x=='+'){
                matrix[k][t]=1;
            }
        }
    }

    backtrack(num+1,1);

    return 0;
}