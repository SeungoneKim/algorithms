#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int main(){

    queue<string> words;

    words.push("one");
    words.push("two");
    words.push("three");

    cout << words.front() << ' ' << words.back() << '\n'; // stack과 다르게 첫 원소, 마지막 원소 모두 접근이 가능하다.
    cout << words.pop(); // stack과 마찬가지로 원소 접근을 하는 front()와 원소를 빼는 pop()을 따로 써야한다.

    cout << words.size() << '\n';

    if(words.empty()){
        cout << "Stack is empty" << '\n';
    }
    else{
        cout << "Stack is not empty" << '\n';
    }

    while(!words.empty()){
        cout << words.front() << '\n';
        words.pop();
    }

    return 0;
}