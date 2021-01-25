#include <cstdio>
#include <stack>
#include <cstring>
using namespace std;

// we will use these as stacks
char l[300001];
char r[300001];
int ln=0;
int rn=0;
char a[31];
char ar[31];
char b[300001];
int n,m;

bool check(int where){
    char*stack=l;
    int len=ln;
    char*str=ar;
    if(where==1){
        stack=r;
        len=rn;
        str=a;
    }
    if(len-n<0){
        return false;
    }
    for(int i=0;i<n;i++){
        if(stack[len-i-1]!=str[i]){
            return false;
        }
    }
    if(where==0){
        ln-=n;
    }
    else{
        rn-=n;
    }
    return true;
}


int main(){

    scanf("%s",a);
    n=strlen(a);
    for(int i=0;i<n;i++){
        ar[i] = a[n-i-1];
    }
    scanf("%s",b);
    m=strlen(b);
    
    int left=0;
    int right=m-1;
    int where=0;
    while(left<=right){
        if(where==0){
            l[ln++]=b[left++];
        }
        else{
            r[rn++]=b[right--];
        }
        if(check(where)){
            where = 1-where;
        }
    }
    for(int i=ln-1;i>=0;i--){
        r[rn++]=l[i];
        check(1);
    }
    for(int i=rn-1;i>=0;i--){
        putchar(r[i]);
    }
    printf("\n");

    return 0;
}