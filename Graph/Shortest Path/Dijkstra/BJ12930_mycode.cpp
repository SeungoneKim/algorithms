#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct Edge{
    int from;
    int to;
    int weight1;
    int weight2;
    Edge(int f,int t,int w1,int w2) : from(f), to(t), weight1(w1), weight2(w2)
    {}
};

int infinity=100000000;

vector<Edge>adjlist[20];

int matrix1[20][20];
int matrix2[20][20];

int dist1[20];
int dist2[20];
bool check[20];

int main(){

    int size;
    cin >> size;

    for(int k=0;k<size;k++){
        for(int t=0;t<size;t++){
            char x;
            cin >> x;
            if(x!='.'){
                matrix1[k][t]=x-'0';
            }
            else{
                matrix1[k][t]=-1;
            }
        }
    }
    for(int k=0;k<size;k++){
        for(int t=0;t<size;t++){
            char x;
            cin >> x;
            if(x!='.'){
                matrix2[k][t]=x-'0';
            }
            else{
                matrix2[k][t]=-1;
            }
        }
    }

    for(int k=0;k<size;k++){
        for(int t=0;t<size;t++){
            if(matrix1[k][t]!=-1){
                adjlist[k].push_back(Edge(k,t,matrix1[k][t],matrix2[k][t]));
            }
        }
    }

    for(int k=0;k<size;k++){
        dist1[k]=infinity;
        dist2[k]=infinity;
    }
    
    dist1[0]=0;
    dist2[0]=0;

    for(int k=0;k<size;k++){
        int m=infinity+1;
        int cur_node=-1;

        for(int t=0;t<size;t++){
            if(dist1[t]*dist2[t]<m && !check[t]){
                cur_node=t;
                m=dist1[t]*dist2[t];
            }
        }
        if(m==infinity+1 || cur_node==-1){
            break;
        }
        check[cur_node]=true;

        for(auto& a : adjlist[cur_node]){
            int next_node = a.to;
            int next_w1=a.weight1;
            int next_w2=a.weight2;
            
                if((dist1[cur_node]+next_w1)*(dist2[cur_node]+next_w2)<dist1[next_node]*dist2[next_node]){
                    dist1[next_node]=dist1[cur_node]+next_w1;
                    dist2[next_node]=dist2[cur_node]+next_w2;
                }
            
        }
    }
    if(dist1[1]==infinity || dist2[1]==infinity){
        cout << -1 << '\n';
        return 0;
    }
    cout << dist1[1]*dist2[1] << '\n';

    return 0;
}