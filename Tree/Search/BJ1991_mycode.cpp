#include <iostream>
#include <vector>

using namespace std;

int tree[27][2];

void preorder(int root){
    if(root ==10000)
        return;
    char print = (char)(root + 64);
    cout << print;
    
    preorder(tree[root][0]);
    preorder(tree[root][1]);
}

void inorder(int root){
    if(root == 10000)
        return;
    char print = (char)(root + 64);

    inorder(tree[root][0]);
    cout << print;
    inorder(tree[root][1]);
}

void postorder(int root){
    if(root == 10000)
        return;
    char print = (char)(root + 64);
    
    postorder(tree[root][0]);
    postorder(tree[root][1]);
    cout << print;
}


int main()
{
    int node;
    cin >> node;
    
    for(int k=1;k<=node;k++){
        char self;
        cin >> self;
        
        char lc,rc;
        // A in 1 , 65-64=1
        cin >> lc >> rc;
        if(lc=='.')
            tree[(int)self-64][0]=10000;
        else
            tree[(int)self-64][0]=(int)lc-64;
        if(rc=='.')
            tree[(int)self-64][1]=10000;
        else
            tree[(int)self-64][1]=(int)rc-64;
    }
    
    preorder(1); cout << endl;
    inorder(1); cout << endl;
    postorder(1);
    
    return 0;
}