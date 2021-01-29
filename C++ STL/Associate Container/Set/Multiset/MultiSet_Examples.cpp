#include <iostream>
#include <set>
#include <functional>

using namespace std;

int main(){

    multiset<int>ms;
    multiset<int>::iterator iter;
    multiset<string,greater<string>> words{"dog","cat","mouse"}; // 비교함수를 바꿀 수도 있다.

    /* Theme 1 : 원소의 추가 */
    ms.insert(50);
    ms.insert(30);
    ms.insert(80);
    ms.insert(80);
    ms.insert(30);
    ms.insert(70);
    iter = ms.insert(10); // 삽입한 원소를 가리키는 반복자를 반환한다.
    cout << "iter's element : " << *iter << endl;

    /* Theme 2 : 원소의 제거 */

    ms.erase(30); // find()를 통해서 해당 원소가 존재하는지 확인한 후에 erase()를 사용하도록 한다.

    /* Theme 3 : 원소에 접근하기 */
    for(iter=ms.begin();iter!= ms.end(); iter++){
        cout << *iter << ' ';
    }
    cout << endl;


    multiset<int>::iterator lower_iter; // 인수와 일치하는 첫 번째 멤버를 가리키는 반복자를 반환한다.
    multiset<int>::iterator upper_iter; // 인수와 일치하는 마지막 멤버 다음 원소를 가리키는 반복자를 반환한다.

    lower_iter=ms.lower_bound(50);
    upper_iter=ms.upper_bound(50);

    cout << "lower_iter : " << *lower_iter << ' '
        << "upper_iter : " << *upper_iter << endl;


    pair<multiset<int>::iterator, multiset<int>::iterator> iter_pair; 
    iter_pair = ms.equal_range(20); // lower_bound()가 반환하는 반복자와 upper_bound()가 반환하는 반복자를 pair로 반환한다

    for(iter=iter_pair.first;iter!=iter_pair.second;++iter){
        cout << *iter << ' ';
    }
    cout << endl;


    auto ptr= ms.find(50); // 인수와 일치하는 첫 번째 원소를 가리키는 반복자를 반환한다. 일치하는 원소가 없으면 끝 반복자를 반환한다.
    if(ptr!=ms.end()){
        cout << *ptr << '\n';
    }

    cout << ms.count(50) << '\n';
    
    return 0;
}

/*
1. insert()함수는 해당 원소가 추가된 주소값을 반환한다.
2. lowerbound()는 인자로 주어진 값보다 큰 최소의 원소의 주소값을 반환한다.
-> 만약 해당 인자값보다 큰 원소가 존재하지 않으면 multiset의 end()와 같은 주소값을 반환한다.
3. erase()함수에 주소값을 가르키는 iterator를 전달해 줌으로써 특정한 원소를 삭제할 수 있다.
*/