#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

bool check[201][201];
bool answ[201];

queue<pair<int,int>>q;

int main(){

    int a,b,c;
    cin >> a >> b >> c;

    int totalsum= c;

    check[0][0]=true;
    answ[c]=true;

    q.push({0,0});

    while(!q.empty()){
        int cura=q.front().first;
        int curb=q.front().second;
        int curc=totalsum-cura-curb;
        q.pop();

        int nexta=cura;
        int nextb=curb;
        int nextc=curc;
        // a->b
        nexta=0;
        nextb= cura+curb;
        if(nextb>=b){
            nexta=nextb-b;
            nextb=b;
        }
        if(!check[nexta][nextb]){
            check[nexta][nextb]=true;
            q.push({nexta,nextb});
            if(nexta==0){
                answ[curc]=true;
            }
        }
        // a->c
        nexta=0;
        nextc= cura+curc;
        if(nextc>=c){
            nexta=nextc-c;
            nextc=c;
        }
        if(!check[nexta][curb]){
            check[nexta][curb]=true;
            q.push({nexta,curb});
            if(nexta==0){
                answ[nextc]=true;
            }
        }
        //b->a
        nextb=0;
        nexta= curb+cura;
        if(nexta>=a){
            nextb=nexta-a;
            nexta= a;
        }
        if(!check[nexta][nextb]){
            check[nexta][nextb]=true;
            q.push({nexta,nextb});
            if(nexta==0){
                answ[curc]=true;
            }
        }
        //b->c
        nextb=0;
        nextc=curb+curc;
        if(nextc>=c){
            nextb=nextc-c;
            nextc= c;
        }
        if(!check[cura][nextb]){
            check[cura][nextb]=true;
            q.push({cura,nextb});
            if(cura==0){
                answ[nextc]=true;
            }
        }
        //c->a
        nextc=0;
        nexta=cura+curc;
        if(nexta>=a){
            nextc=nexta-a;
            nexta=a;
        }
        if(!check[nexta][curb]){
            check[nexta][curb]=true;
            q.push({nexta,curb});
            if(nexta==0){
                answ[nextc]=true;
            }
        }
        //c->b
        nextc=0;
        nextb=curb+curc;
        if(nextb>=b){
            nextc=nextb-b;
            nextb=b;
        }
        if(!check[cura][nextb]){
            check[cura][nextb]=true;
            q.push({cura,nextb});
            if(cura==0){
                answ[nextc]=true;
            }
        }
    }

    for(int k=0;k<=c;k++){
        if(answ[k]==true){
            cout << k << ' ';
        }
    }
    cout << '\n';

    return 0;
}