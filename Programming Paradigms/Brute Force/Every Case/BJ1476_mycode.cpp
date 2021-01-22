#include <iostream>

using namespace std;

int main(){
    int e=1,s=1,m=1;
    
    cin >> e >> s >> m;
    
    int sum=1;
    while(e!=1 || s!=1 || m!=1)
    {
        if(e==1)
            e=15;
        else
            e--;
        if(s==1)
            s=28;
        else
            s--;
        if(m==1)
            m=19;
        else
            m--;
        
        sum++;
    }
    
    cout << sum;
    
}