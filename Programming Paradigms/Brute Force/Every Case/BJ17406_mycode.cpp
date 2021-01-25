#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void go(vector<vector<int>>&a, tuple<int,int,int>t){
    int row,col,size;
    tie(row,col,size)=t;
    vector<vector<int>>groups;

    for(int s=1;s<=size;s++){
        vector<int>group;
        for(int r=row-s,c=col-s;c<col+s;c++){
            group.push_back(a[r][c]);
        }
        for(int r=row-s,c=col+s;r<row+s;r++){
            group.push_back(a[r][c]);
        }
        for(int r=row+s,c=col+s;c>col-s;c--){
            group.push_back(a[r][c]);
        }
        for(int r=row+s,c=col-s;r>row-s;r--){
            group.push_back(a[r][c]);
        }
        groups.push_back(group);
    }

    for(int s=1;s<=size;s++){
        auto& group = groups[s-1];
        rotate(group.rbegin(),group.rbegin()+1,group.rend());
        int len=group.size();
        int index=0;
        for(int r=row-s,c=col-s;c<col+s;c++){
            a[r][c]=group[index++];
        }
        for(int r=row-s,c=col+s;r<row+s;r++){
            a[r][c]=group[index++];
        }
        for(int r=row+s,c=col+s;c>col-s;c--){
            a[r][c]=group[index++];
        }
        for(int r=row+s,c=col-s;r>row-s;r--){
            a[r][c]=group[index++];
        }
    }
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int rownum,colnum,query_num;
    cin >> rownum >> colnum >> query_num;

    vector<vector<int>>a(rownum,vector<int>(colnum));
    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cin >> a[r][c];
        }
    }
    
    vector<tuple<int,int,int>>d(query_num);
    for(int i=0;i<query_num;i++){
        int r,c,s;
        cin >> r >> c >> s;
        d[i]=make_tuple(r-1,c-1,s);
    }
    sort(d.begin(),d.end());
    int answ=1000000000;
    do{
        auto b=a;
        for(auto&t : d){
            go(b,t);
        }
        for(int i=0;i<rownum;i++){
            int sum=0;
            for(int j=0;j<colnum;j++){
                sum+=b[i][j];
            }
            if(answ>sum) answ=sum;
        }
    }while(next_permutation(d.begin(),d.end()));
    
    cout << answ << '\n';

    return 0;
}
