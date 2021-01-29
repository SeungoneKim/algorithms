#include <iostream>
#include <cstring>
#include <deque>

using namespace std;

int main(){

    deque<int> a_deque;
    deque<int> my_deque(10);
    deque<string> words{"ones","none","some","all","none","most","many"};
    deque<int> numbers{2,3,4};

    /* Theme1 : 원소에 접근하기 */

    cout << words.size() << '\n'; // deque는 내부 저장 방식 때문에 크기와 용량이 항상 같아서 capacity()가 정의되어 있지 않다.

    cout << words[0] << '\n';
    cout << words.at(1) << '\n';

    cout << words.front() << ' ' << words.back() << '\n';
    words.resize(10);

    /* Theme 2 : 원소 추가 & 제거 */

    // 벡터와 다르게 push_front, pop_front의 옵션도 존재한다
    numbers.push_front(12);
    numbers.push_back(11);
    numbers.pop_front();

    // 벡터에 존재하는 모든 추가 & 제거 관련 메소드와 함수들은 덱에서도 사용할 수 있다.
    numbers.emplace_back(7);
    numbers.emplace_front(8);
    numbers.insert(numbers.begin(),5);

    numbers.erase(remove(numbers.begin(),numbers.end(),4).numbers.end());
    numbers.clear();

    return 0;
}