#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int dr[4]={1,-1,0,0};
int dc[4]={0,0,1,-1};

char matrix[51][51];
int matrix_num[51][51];
int bend[2501];
bool bend_check[2501];

int main(){

    int size;
    cin >> size;

    int start=-1,end=-1;

    vector<pair<int,int>>mirrors;

    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            matrix_num[r][c]=-1;
        }
    }

    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            cin >> matrix[r][c];
            if(matrix[r][c]=='#'){
                if(start==-1){
                    start= mirrors.size();
                }
                else{
                    end=mirrors.size();
                }
                mirrors.push_back({r,c});
                matrix_num[r][c]=mirrors.size()-1;
            }
            else if(matrix[r][c]=='!'){
                mirrors.push_back({r,c});
                matrix_num[r][c]=mirrors.size()-1;
            }
        }
    }

    int cnt=mirrors.size();

    vector<vector<bool>> can_arrive(cnt,vector<bool>(cnt,false));
    for(int i=0;i<cnt;i++){
        for(int k=0;k<4;k++){
            int curr=mirrors[i].first;
            int curc=mirrors[i].second;
            int t=1;
            int nextr=curr+t*dr[k];
            int nextc=curc+t*dc[k];
            while(1<=nextr && nextr<=size && 1<=nextc && nextc<=size){
                if(matrix[nextr][nextc]=='!' || matrix[nextr][nextc]=='#'){
                   can_arrive[i][matrix_num[nextr][nextc]]=true;
                }
                else if(matrix[nextr][nextc]=='*'){
                    break;
                }
                t++;
                nextr=curr+t*dr[k];
                nextc=curc+t*dc[k];
            }
        }
    }
    /*
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            cout << matrix[r][c];
        }
        cout << '\n';
    }
    for(int r=1;r<=size;r++){
        for(int c=1;c<=size;c++){
            cout << matrix_num[r][c];
        }
        cout << '\n';
    }
    for(int k=0;k<cnt;k++){
        cout << mirrors[k].first << ' ' << mirrors[k].second << '\n';
    }
    for(int k=0;k<cnt;k++){
        for(int t=0;t<cnt;t++){
            cout << can_arrive[k][t];
        }
        cout << '\n';
    }
    */

    queue<pair<int,int>>q;
    q.push({mirrors[start].first,mirrors[start].second});
    
    while(!q.empty()){
        int curr=q.front().first;
        int curc=q.front().second;
        q.pop();
        for(int k=0;k<cnt;k++){
            if(can_arrive[matrix_num[curr][curc]][k]==true){
                if(bend_check[k]==false){
                    bend_check[k]=true;
                    bend[k] = bend[matrix_num[curr][curc]]+1;
                    q.push({mirrors[k].first,mirrors[k].second});
                }
            }
        }
    }
    
    cout << bend[end]-1 << '\n';

    return 0;
}