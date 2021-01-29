#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int main(){

    stack<string> words;

    words.push("one");
    words.push("two");
    words.push("three");

    cout << words.top() << '\n';
    words.pop(); // pop()을 하면서 가장 위에 있던 원소를 반환하지 않는다는 것을 알아야한다. 즉, top()을 통해 access하고, pop()을 해야한다.

    cout << words.size() << '\n';

    if(words.empty()){
        cout << "Stack is empty" << '\n';
    }
    else{
        cout << "Stack is not empty" << '\n';
    }


    return 0;
}