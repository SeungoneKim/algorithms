#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

char matrix[15][15];

int main(){

    int rownum,colnum;
    cin >> rownum >> colnum;

    for(int r=0;r<rownum;r++){
        for(int c=0;c<colnum;c++){
            cin >> matrix[r][c];
        }
    }

    int answ=0;
    for(int x1=0;x1<rownum;x1++){
        for(int y1=0;y1<colnum;y1++){
            for(int s1=0;;s1++){
                if(x1-s1<0 || x1+s1>=rownum) break;
                if(y1-s1<0 || y1+s1>=colnum) break;
                if(matrix[x1-s1][y1]!='#' || matrix[x1+s1][y1]!='#') break;
                if(matrix[x1][y1-s1]!='#' || matrix[x1][y1+s1]!='#') break;
                matrix[x1-s1][y1]='*'; matrix[x1+s1][y1]='*';
                matrix[x1][y1-s1]='*'; matrix[x1][y1+s1]='*';
                
                for(int x2=0;x2<rownum;x2++){
                    for(int y2=0;y2<colnum;y2++){
                        for(int s2=0;;s2++){
                            if(x2-s2<0 || x2+s2>=rownum) break;
                            if(y2-s2<0 || y2+s2>=colnum) break;
                            if(matrix[x2-s2][y2]!='#' || matrix[x2+s2][y2]!='#') break;
                            if(matrix[x2][y2-s2]!='#' || matrix[x2][y2+s2]!='#') break;
                            
                            int area=(4*s1+1)*(4*s2+1);
                            if(answ<area) answ=area;
                        }
                    }
                }
            }
            for(int s1=0;;s1++){
                if(x1-s1<0 || x1+s1>=rownum) break;
                if(y1-s1<0 || y1+s1>=colnum) break;
                if(matrix[x1-s1][y1]!='*' || matrix[x1+s1][y1]!='*') break;
                if(matrix[x1][y1-s1]!='*' || matrix[x1][y1+s1]!='*') break;
                matrix[x1-s1][y1]='#'; matrix[x1+s1][y1]='#';
                matrix[x1][y1-s1]='#'; matrix[x1][y1+s1]='#';
            }
        }
    }

    cout << answ << '\n';

    return 0;
}