#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

/*
    let each square's index start from 1.
    however, squareyes's index is calculated as considering the square's index started from 0
*/

int matrix[10][10];

bool rowyes[10][10]; 
bool colyes[10][10];
bool squareyes[10][10];
bool which_domino[10][10];

bool flg=false;
int glbidx=1;

void backtrack(int num, int s){
    /*
        state default=0 : this indicates that it is impossible to put in domino
        state 1 : should put in horizontal
        state 2 : should put in vertical
        // we consider 1 has priority of 2 when both is possible
    */
   int state=s;
    if(num==81){
        for(int r=1;r<=9;r++){
            for(int c=1;c<=9;c++){
                cout << matrix[r][c];
            }
            cout << '\n';
        }
        flg=true;
        return;
    }

    int r= (num/9)+1;
    int c= (num%9)+1;
    
    bool tmpflg=false;
    if(matrix[r][c]!=0){
        backtrack(num+1,0);
    }
    if(matrix[r][c]==0 && r+1<=9){
        if(matrix[r+1][c]==0){
            state=2;
            int n1=0,n2=0;

        for(int a=1;a<=9;a++){
            for(int b=1;b<=9;b++){
                if(which_domino[a][b]==false && a!=b){
                    n1=a;
                    n2=b;

                    if(rowyes[r][n1]==false && rowyes[r+1][n2]==false && colyes[c][n1]==false && colyes[c][n2]==false){
            if(squareyes[(((r-1)/3)*3) + ((c-1)/3)][n1]==false && squareyes[(((r)/3)*3) + ((c-1)/3)][n2]==false){
                // cout << glbidx << ' ' << state << ' ' << r << ' ' << c << ' ' << n1 << ' ' << n2 << '\n';
                
                matrix[r][c]=n1;
                matrix[r+1][c]=n2;
                which_domino[n1][n2]=true;
                which_domino[n2][n1]=true;

                rowyes[r][n1]=true;
                colyes[c][n1]=true;
                squareyes[(((r-1)/3)*3) + ((c-1)/3)][n1]=true;

                rowyes[r+1][n2]=true;
                colyes[c][n2]=true;
                squareyes[(((r)/3)*3) + ((c-1)/3)][n2]=true;

                backtrack(num+1,0);

                matrix[r][c]=0;
                matrix[r+1][c]=0;
                which_domino[n1][n2]=false;
                which_domino[n2][n1]=false;

                rowyes[r][n1]=false;
                colyes[c][n1]=false;
                squareyes[(((r-1)/3)*3) + ((c-1)/3)][n1]=false;

                rowyes[r+1][n2]=false;
                colyes[c][n2]=false;
                squareyes[(((r)/3)*3) + ((c-1)/3)][n2]=false;

                if(flg){
                    return;
                }
            }
        }
                }
            }
        }

        }
    }
    if(matrix[r][c]==0 && c+1<=9){
        if(matrix[r][c+1]==0){
            state=1;
            int n1=0,n2=0;

        for(int a=1;a<=9;a++){
            for(int b=1;b<=9;b++){
                if(which_domino[a][b]==false && a!=b){
                    n1=a;
                    n2=b;

                    if(rowyes[r][n1]==false && rowyes[r][n2]==false && colyes[c][n1]==false && colyes[c+1][n2]==false){
            if(squareyes[(((r-1)/3)*3) + ((c-1)/3)][n1]==false && squareyes[(((r-1)/3)*3) + ((c)/3)][n2]==false){
                // cout << glbidx << ' ' << state << ' ' << r << ' ' << c << ' ' << n1 << ' ' << n2 << '\n';
                
                matrix[r][c]=n1;
                matrix[r][c+1]=n2;
                which_domino[n1][n2]=true;
                which_domino[n2][n1]=true;

                rowyes[r][n1]=true;
                colyes[c][n1]=true;
                squareyes[(((r-1)/3)*3) + ((c-1)/3)][n1]=true;

                rowyes[r][n2]=true;
                colyes[c+1][n2]=true;
                squareyes[(((r-1)/3)*3) + ((c)/3)][n2]=true;

                backtrack(num+1,0);

                matrix[r][c]=0;
                matrix[r][c+1]=0;
                which_domino[n1][n2]=false;
                which_domino[n2][n1]=false;

                rowyes[r][n1]=false;
                colyes[c][n1]=false;
                squareyes[(((r-1)/3)*3) + ((c-1)/3)][n1]=false;

                rowyes[r][n2]=false;
                colyes[c+1][n2]=false;
                squareyes[(((r-1)/3)*3) + ((c)/3)][n2]=false;

                if(flg){
                    return;
                }
            }
        }
                }
            }
        }
        }
    }

    
    // cout << glbidx << ' ' << state << ' ' << r << ' ' << c << '\n';

    

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    while(n!=0){

        while(n--){
            int a, b;
            string posa, posb;

            cin >> a >> posa >> b >> posb;
            
            matrix[posa[0]-'A'+1][posa[1]-'1'+1]=a;
            matrix[posb[0]-'A'+1][posb[1]-'1'+1]=b;
            which_domino[a][b]=true;
            which_domino[b][a]=true;

            rowyes[posa[0]-'A'+1][a]=true;
            rowyes[posb[0]-'A'+1][b]=true;
            colyes[posa[1]-'1'+1][a]=true;
            colyes[posb[1]-'1'+1][b]=true;
            squareyes[((posa[0]-'A')/3)*3 + ((posa[1]-'1')/3)][a]=true;
            squareyes[((posb[0]-'A')/3)*3 + ((posb[1]-'1')/3)][b]=true;
        }
        int tmpidx=1;
        while(tmpidx<10){
            string c;
            cin >> c;

            matrix[c[0]-'A'+1][c[1]-'1'+1]=tmpidx;
            which_domino[tmpidx][tmpidx]=true;

            rowyes[c[0]-'A'+1][tmpidx]=true;
            colyes[c[1]-'1'+1][tmpidx]=true;
            squareyes[((c[0]-'A')/3)*3 + ((c[1]-'1')/3)][tmpidx]=true;

            tmpidx++;
        }

        cout << "Puzzle " << glbidx << '\n';
        backtrack(0,0);

        memset(matrix,0,sizeof(matrix));
        memset(rowyes,false,sizeof(rowyes));
        memset(colyes,false,sizeof(colyes));
        memset(squareyes,false,sizeof(squareyes));
        memset(which_domino,false,sizeof(which_domino));
        flg=false;
        glbidx++;

        cin >> n;
    }



    return 0;
}