#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
string add(string a, string b) {
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    string c = "";
    int carry = 0;
    while (a.length() < b.length()) {
        a += "0";
    }
    while (b.length() < a.length()) {
        b += "0";
    }
    int len = a.length();
    for (int i=0; i<len; i++) {
        int temp = (a[i]-'0') + (b[i]-'0') + carry;
        c += (char)(temp % 10 + '0');
        carry = temp / 10;
    }
    if (carry) {
        c += (char)(carry + '0');
    }
    reverse(c.begin(), c.end());
    return c;
}
int main() {
    vector<string> d(10001);
    d[0] = "1";
    d[1] = "1";
    d[2] = "3";
    for (int i=3; i<=10000; i++) {
        d[i] = add(d[i-1], d[i-2]);
    }
    int n;
    while (cin >> n) {
        cout << d[n] << '\n';
    }
    return 0;
}