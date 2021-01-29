#include <iostream>
#include <cstring>
#include <list>

using namespace std;

int main(){

    list<string>words;
    list<string>sayings(20);
    list<double>values(50,3.141592);

    list<double>samples{++values.cbegin(),--values.cend()};

    cout << values.size() << '\n';

    /* Theme 1 : 원소 추가하기 */
    words.push_front("apple");
    words.push_back("banana");

    words.emplace_front("company");
    words.emplace_back("delta");

    words.insert(++words.begin(),"energy");

    auto iter = words.begin();
    advance(iter,3); // advance()를 이용해서 반복자가 가리키는 위치를 변경시킬 수 있다.
    words.insert(iter,"foxtrot");

    /* Theme 2 : 원소 삭제하기 */
    words.remove("banana"); // remove()는 vector,deque와는 다르게 메소드로써 특정 값을 삭제하는 역할을 한다.
    words.unique(); // unique()는 중복하는 원소들이 있으면 첫 번째만 남겨두고 나머지를 제거한다.

    /* Theme 3 : 원소를 정렬하고 병합하기 */
    words.sort(greater<string>()); // sort()는 메소드로써 정렬을 하게 되며, 비교연산을 할 함수 또는 템플릿을 인자로 전달해주어야 한다.

    /* Theme 4 : 원소 접근하기 */
    // list에서는 인덱스를 이용해서 원소에 접근할 수 없다.
    // begin()과 end()는 양방향 반복자를 반환하므로 정숫값을 더하거나 빼서는 안되고, 증가&감소 연산자를 사용해야한다.
    for(auto& name : words){
        cout << name << ' ';
    }
    cout << '\n';

    // 반복자를 증가,감소 연산자로 하나씩 이동시키면서 접근해야한다.
    auto iter1= words.begin();
    auto iter2= words.end();
    while(iter1!=iter2){
        cout << *iter1++ << '\n';
    }

    return 0;
}