#include <iostream>
#include <map>
#include <cstring>

using namespace std;

int main(){
    // multimap에 있는 대부분의 함수는 map의 함수처럼 동작한다. 컨테이너의 중복 키를 처리하는 부분에서만 차이가 발생한다.

    multimap<string,string>pets;
    multimap<string,size_t> people{ {"Ann",25}, {"Bill",46}, {"Jack",77}, {"Jack",32}, {"Jill",32}, {"Ann",35} };

    /* Theme 1 : 원소 삽입하기 */

    // multimap은 키 하나가 원소 하나만 가리키는 것이 아니므로 첨자연산자는 지원하지 않는다.
    // 마찬가지로 at() 함수도 multimap에서는 이용할 수 없다.

    // insert 멤버는 하나 이상의 원소를 삽입하고, 항상 실행에 성공한다.
    auto iter= pets.insert({"dog","Fang"});
    iter = pets.insert(iter,{"dog","Spot"}); // Fang 앞에 Spot 를 삽입
    pets.insert({"dog","Rover"}); // Fang 뒤에 Rover를 삽입

    pets.insert({"cat","Korky"}); // 모든 dog 앞에 삽입

    pets.insert({{"rat","Roland"},{"pig","Pinky"},{"pig","Perky"}}); //  리스트 원소를 전달하여 한번에 insert를 하는 것도 가능하다

    
    /* Theme 2 : 원소에 접근하기 */

    // for문을 통한 접근
    for(auto&a : people){
        cout << a.first << ' ' << a.second << '\n';
    }

    // count()함수
    cout << people.count("Ann") << '\n';

    // find()함수
    string name = "Bill";
    auto iter2 = people.find(name); // find()를 통해서 multimap의 원소중에서 find()에 전달된 인자와 같은 키를 가진 원소를 가리키는 반복자를 반환한다. 마찬가지로 키를 발견하지 못하면 컨테이너의 끝 반복자를 반환한다.

    // find()는 중복키를 어떻게 처리할지 보장이 되지 않는다. equal_range()는 동등한 키를 갖는 원소 범위를 pair 객체로 캡슐화한 반복자 쌍을 반환한다.
    // equal_range()를 통해서 해당 키를 가진 모든 원소들에 접근할 수 있다.
    auto pr = people.equal_range("Ann");
    if(pr.first!=people.end()){
        for(auto iter=pr.first; iter!=pr.second; iter++){
            cout << iter->first << ' ' << iter->second << '\n';
        }
    }

    // equal_range()를 만들어서 반복자에 후위덧셈연산자를 사용하지 않고, 반복자를 더해나갈 수 있다.
    auto iter3= people.lower_bound("Jack"); // 인수와 같거나 보다 큰 키를 갖는 첫번째 원소를 가리키는 반복자를 반환한다.
    auto iter4= people.upper_bound("Jack"); // 인수보다 큰 키를 갖는 첫 번째 원소를 가리키는 반복자를 반환한다.
    cout << iter3->first << ' ' << iter3->second << '\n';
    cout << iter4->first << ' ' << iter4->second << '\n';
    if(iter3!= people.end()){
        for(auto iter=iter3;iter!=iter4;++iter){
            cout << iter->first << ' ' << iter->second << '\n';
        }
    }


    /* Theme 3 : 원소 삭제하기 */

    people.erase(iter2); // 반복자를 인자로 받으면 해당 원소만 삭제한다.
    auto iter5 = people.erase(iter3,iter4); // 반복자 2개를 전달하면 해당 범위의 원소들을 모두 삭제한다. 제거한 마지막 원소의 다음 원소를 가리키는 반복자를 반환한다.
    auto iter6 = people.erase("Ann"); // 키를 인자로 받으면 해당 키를 갖는 원소를 모두 삭제한다. 제거된 원소의 개수를 반환한다.

    return 0;
}