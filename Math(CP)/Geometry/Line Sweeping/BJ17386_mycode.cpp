#include <iostream>
#include <algorithm>

using namespace std;

int ccw(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3){
    long long temp= x1*y2+x2*y3+x3*y1;
    temp = temp-x2*y1-x3*y2-y3*x1;
    if(temp>0) return 1;
    else if(temp<0) return -1;
    else return 0;
}

int main(){

    long long x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;

    long long x3,y3,x4,y4;
    cin >> x3 >> y3 >> x4 >> y4;

    int a= ccw(x1,y1,x2,y2,x3,y3);
    int b= ccw(x1,y1,x2,y2,x4,y4);
    int c= ccw(x3,y3,x4,y4,x1,y1);
    int d= ccw(x3,y3,x4,y4,x2,y2);

    if(a*b<=0 && c*d<=0){
        cout << 1 << '\n';
    }
    else{
        cout << 0 << '\n';
    }

    return 0;
}