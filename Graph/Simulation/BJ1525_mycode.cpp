#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int answ=123456789;
bool found_answ=false;

int main(){

    int init_state=0;
    int idx=9;
    while(idx--){
        int tmp;
        cin >> tmp;
        if(tmp==0){
            tmp=9;
        }
        init_state = 10*init_state+tmp;   
    }

    if(init_state==answ){
        cout << 0 << '\n';
        return 0;
    }

    map<int,int>m;
    queue<int>q;
    
    m[init_state]=0;
    q.push(init_state);
    while(!q.empty()){
        bool flg=false;
        int cur=q.front();
        q.pop();
        string cur_s = to_string(cur);
        int idx= cur_s.find('9');
        int row=idx/3;
        int col=idx-3*row;

        for(int k=0;k<4;k++){
            int nr=row+dx[k];
            int nc=col+dy[k];
            if(0<=nr && nr<=2 && 0<=nc && nc<=2){
                string next=cur_s;
                swap(next[nr*3+nc],next[row*3+col]);
                int num=stoi(next);
                if(m.count(num)==0){
                    m[num]=m[cur]+1;
                    q.push(num);
                    if(num==answ){
                        flg=true;
                        break;
                    }
                }
            }
        }
        if(flg){
            found_answ=true;
            break;
        }
    }

    if(found_answ){
        cout << m[answ] << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}