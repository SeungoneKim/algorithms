#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> perm(12);
vector<int> selected(12);

int main(){

    int howmuch=0;
    cin >> howmuch;
    while(howmuch!=0){

        perm.resize(howmuch);
        for(int k=0;k<howmuch;k++){
            cin >> perm[k];
        }

        selected.resize(howmuch);
        for(int k=0;k<howmuch;k++){
            if(k<6) selected[k]=1;
            else{
                selected[k]=0;
            }
        }

        do{
            for(int k=0;k<howmuch;k++){
                if(selected[k]==1){
                    cout << perm[k] << ' ';
                }
            }
            cout << '\n';
        }while(prev_permutation(selected.begin(),selected.end()));
        
        cout << '\n';
        cin >> howmuch;
    }


    return 0;
}