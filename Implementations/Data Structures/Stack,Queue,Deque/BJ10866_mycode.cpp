#include <iostream>
#include <deque>

using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int cmdnum;
    cin >> cmdnum;

    deque<int> d;

    for(int k=1;k<=cmdnum;k++){
        string cmd;
        cin >> cmd;
        if(cmd=="push_back"){
            int n;
            cin >> n;
            d.push_back(n);
        }
        else if(cmd=="push_front"){
            int n;
            cin >> n;
            d.push_front(n);
        }
        else if(cmd=="front"){
            if(d.size()==0){
                cout << -1 << '\n';
            }
            else{
                cout << d.front() << '\n';
            }
        }
        else if(cmd=="back"){
            if(d.size()==0){
                cout << -1 << '\n';
            }
            else{
                cout << d.back() << '\n';
            }
        }
        else if(cmd=="size"){
            cout << d.size() << '\n';
        }
        else if(cmd=="pop_front"){
            if(d.size()==0){
                cout << -1 << '\n';
            }
            else{
                cout << d.front() << '\n';
                d.pop_front();
            }
        }
        else if(cmd=="pop_back"){
            if(d.size()==0){
                cout << -1 << '\n';
            }
            else{
                cout << d.back() << '\n';
                d.pop_back();
            }
        }
        else{ // cmd=="empty"
            if(d.size()==0){
                cout << 1 << '\n';
            }
            else{
                cout << 0 << '\n';
            }
        }
    }

    return 0;
}