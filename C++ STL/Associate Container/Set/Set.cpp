#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

int main(){
    set<int> s;
    set<int>::iterator it;
    set<int> numbers{8,7,6,5,4,3,2,1};
    set<string,greater<string>> words {"one","two","three","four","five","six","seven","eight"}; // 비교 함수를 바꿀 수도 았다.

    if(!numbers.empty())
        cout << numbers.size() << '\n';
    
    /* Theme 1 : 원소의 추가 */
    s.insert(4);               //s : 4
    s.insert(1);               //s : 1 4
    s.insert(2);               //s : 1 2 4

    auto pr1 = words.insert("nine"); // first로 새 원소를 가리키는 반복자를 반환하고, second로 true를 반환한다.
    auto pr2 = words.insert("two"); // first로 기존 원소를 가리키는 반복자를 반환하고, second로 false를 반환한다.
    auto pr3 = words.insert(pr1.first,"ten"); // ir3은 "nine" 앞에 삽입된 새 원소를 가리키며, true를 반환한다.
    

    vector<int> v;
    v.push_back(3);            //v : 3
    v.push_back(5);            //v : 3 5
    v.push_back(6);            //v : 3 5 6
    
    s.insert(v.begin(), v.end());        //s : 1 2 3 4 5 6 , 벡터를 범위째로 삽입하는 것도 가능하다.


    /* Theme 2 : 원소의 제거 */
    s.erase(4);                //s : 1 2 3 5 6
    s.erase(s.begin());        //s : 2 3 5 6 , 반복자가 가리키는 원소를 삭제할 수 있다.
    auto pr4= s.erase(s.begin()); // s : 3 5 6 , 제거된 원소의 다음 원소를 가리키는 반복자를 반환한다.
    auto pr5= s.erase(6); // s : 3 5 , 제거된 원소의 개수를 반환한다.
    
    
    // find()를 통해서 해당 원소가 존재하는지 확인한 후에 erase()를 사용하도록 한다.
    int toErase;
    scanf("%d", &toErase);
    it = s.find(toErase);
    if(it != s.end())
        s.erase(it);

    s.clear(); // 모든 원소를 제거할 수 있다.


    /* Theme 3 : 원소에 접근하기 */
    auto iter = words.find("one"); // "one"을 가리키는 반복자를 반환한다.

    cout << words.count("one") << '\n'; // 해당 원소의 개수를 반환한다.

    // equal_range(), lower_bound(), upper_bound()는 주로 multiset에서 더 쓰인다.

    return 0;
}