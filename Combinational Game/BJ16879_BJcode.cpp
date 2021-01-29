#include <iostream>
#include <cstring>
#include <string>
using namespace std;
string original;
int total;
int d[10000][101];
int go(string num, int turn) {
    if (turn == total+1) {
        if (num > original) {
            return 1;
        } else {
            return 0;
        }
    }
    int x = stoi(num);
    int &ans = d[x][turn];
    if (ans != -1) {
        return ans;
    }
    if (turn % 2 == 0) {
        ans = 1;
    } else {
        ans = 0;
    }
    for (int i=0; i<4; i++) {
        string temp = num;
        if (temp[i] == '9') {
            temp[i] = '0';
        } else {
            temp[i] += 1;
        }
        if (turn % 2 == 0) {
            ans &= go(temp, turn+1);
        } else {
            ans |= go(temp, turn+1);
        }
    }
    return ans;
}
int main() {
    cin >> original >> total;
    memset(d,-1,sizeof(d));
    if (go(original, 1) == 1) {
        cout << "koosaga" << '\n';
    } else {
        cout << "cubelover" << '\n';
    }
    return 0;
}