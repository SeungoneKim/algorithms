#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main(){

    vector<double> values; // 원소가 하나도 없고, 원소를 위해서 할당된 공간도 없는 상태이다.
    values.reserve(20); // reserve()를 호출해서 용량을 늘릴 수 있다. 기존의 반복자들은 무효화되므로 다시 생성해야한다.

    vector<unsigned int> primes{2u,3u,5u,7u,11u,13u,17u,19u}; // 초깃값을 지정하고, 원소들의 개수를 미리 지정할 수 있다.

    vector<double> values2(20); // vector를 생성할 때, 초기 크기를 설정하는 방법이 있다.
    vector<long long> numbers(20,99LL); // 초기 크기를 설정하면서 모든 원소를 초기화시킬 수 있다.

    vector<string>words{"one","two","three","four","five"};

    vector<int> example1[10]; // 2차원 벡터
    vector<vector<int>> example2(20,vector<int>(10),0); // 20*10 벡터할당, 원소는 모두 0으로 초기화


    /* Theme1 : 벡터의 용량과 크기 */
    cout << primes.size() << '\n'; // size()는 컨테이너의 크기(원소의 개수)를 불러온다.
    cout << primes.capacity() << '\n'; // capacity()는 컨테이너의 용량(할당한 메모리 크기)를 불러온다.

    auto nElements= primes.size(); // size()는 size_t 타입으므로, int 대신에 auto로 저장해준다.

    values.resize(5,1); // resize()를 통해 크기를 바꾸고, 초기화시킬 수 있다. 단, 기존 원소의 개수보다 크기를 줄여도 용량은 바뀌지 않는다.
    values.resize(4);
    values.resize(7,99); // 크기를 늘리면서 초기화하면, 새로 늘어난 원소들만 초기화된다.


    /* Theme2 : 원소에 접근하기 */
    for(auto& prime : primes){
        prime *= 2;
    }

    values2[0]=3.141592;
    values2[1]=5.0;
    values2[2]=2.0*values2[0]*values2[1];

    cout << values2.at(2) << '\n'; // at()을 사용하면 경계 검사를 하고 원소에 접근할 수 있다.

    cout << values2.front() << ' ' << values2.back() << '\n'; // front()를 이용해서 첫 원소에, back()를 이용해서 마지막 원소에 접근 할 수 있다.
    values2.front()=1; // front()와 back()은 참조를 반환하므로 할당하는데 사용할 수도 있다.

    auto pdata= values2.data(); // data()는 vector 내부에서 원소를 저장하는 배열에 대한 포인터를 반환한다. 이는 사용할만한 이유가 있을 때만 사용해야한다.


    /* Theme3 : 반복자 사용하기 */
    auto ptr1= values.begin(); // begin()은 첫 원소를 가리키는 반복자를 반환한다.
    auto ptr2= values.end(); // end()는 마지막 원소보다 한 칸 뒤를 가리키는 반복자를 반환한다.

    // sort()에 대해서는 algorithm에서 다시 다루기로 한다.
    sort(values.begin(),values.end()); // sort()에 인자로 정렬의 시작범위를 가리키는 반복자와 마지막범위보다 한 칸 뒤를 가리키는 반복자를 전달하여서 정렬할 수 있다.
    sort(values.begin(),values.end(),greater<double>()); // 뒤에 greater<T>()를 전달하여서 내림차순으로 정렬되게 할 수 있다.
    
    auto riter= find(words.rbegin(),words.rend(),"one"); // find()는 범위 지정에 사용할 수 있는 타입의 반복자를 반환하며, 찾지 못하면 마지막원소보다 한칸 옆의 반복자를 반환한다.


    /* Theme4 : 새 원소 추가하기 */
    values.push_back(3.141592); // push_back()을 통해서 벡터의 끝에 원소를 추가할 수 있다. 메모리가 부족하다면, 메모리 할당도 자연스럽게 일어난다.
    values.insert(values.begin(),2.28); // insert()를 통해서 벡터에서 지정한 위치에 원소를 추가할 수 있다.
    
    double arr[3]={1.1,2.2,3.3};
    values.insert(values.begin(),begin(arr),end(arr)); // 배열을 대상으로 한꺼번에 벡터에 insert()하는 것도 가능하다.
    values.insert(values.begin(),2,0.1234); // 두번째 인자 횟수만큼 세번째 인자를 insert()한다

    // emplace_back()과 emplace()는 각각 push_back()과 insert()와 다르게 복사본을 만들지 않고, 생성자를 호출하여 복사연산이 생략된다.
    words.emplace_back("facetious"); // push_back()과 비교했을 때, 복사 연산이 사라져서 더 효율적이다.
    string str{"alleged"};
    words.emplace_back(str,2,3); // str에서 2번째 인덱스부터 연속 3문자로 된 서브문자열을 emplace_back()한다.
    
    auto iter = words.emplace(++words.begin(),5,'A'); // emplace()는 삽입할 위치를 가리키는 반복자로 사용한다. 삽입된 원소를 가리키는 반복자를 반환한다.
    words.emplace(++iter,"$$$$");

    /* Theme5 : 원소 삭제하기 */
    values.clear(); // clear()는 원소들을 모두 제거한다. 단, 용량은 바뀌지 않는다.

    values2.pop_back(); // pop_back()는 마지막 원소 하나를 제거할 수 있다.

    // i번째 원소를 없애고 싶으면 swap()한 후에 pop_back()하는 방법이 있다.
    swap(words.begin()+1,words.end()-1);
    words.pop_back();

    values2.shrink_to_fit(); // shrink_to_fit()은 현재 원소의 개수에 맞게 용량을 줄일 수 있다.

    auto iter4= primes.erase(primes.begin()+1); // 특정한 인덱스를 가리키는 반복자를 인자로 전달하여서 원소를 삭제할 수 있다.
    auto iter5= primes.erase(primes.begin()+2,primes.begin()+4); // 첫 인자부터 마지막인자의 한칸 전 범위까지 원소를 삭제할 수 있다.

    // remove()는 세번째 해당하는 원소들을 벡터에서 모두 삭제한다. 단, size()는 바뀌지 않는데 이는 해당 원소가 "" 또는 0으로 대체되어서 뒤로 이동하기 때문이다.
    auto iter6= remove(words.begin(),words.end(),"five"); // 첫인자부터 두번째인자의 한칸 전 범위까지 세번째 인자를 탐색하여 있으면 삭제한다.
    auto iter7= primes.erase(remove(primes.begin(),primes.end(),7u),primes.end()); // 이와 같이 처리하면 size()가 바뀌지 않고 잉여 원소들이 뒤에 남아있는 문제를 해결할 수 있다.
    primes.erase(unique(primes.begin(),primes.end()),primes.end());

    return 0;
}