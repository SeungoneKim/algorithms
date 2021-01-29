#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int main(){

    // algorithm 헤더에 정의된 sort<Iter>() 함수 템플릿은 범위로 지정된 원소들을 오름차순으로 정렬한다.
    // 단, 정렬하려는 객체의 타입에서 < 연산자를 지원한다고 가정한다.
    // 또, 정렬하려는 객체들은 반드시 교환 가능(swappable)해야 한다. -> 이동 생성자와 이동 할당 연산자를 반드시 구현해야 한다.
    // 랜덤 엑세스 반복자를 제공하는 컨테이너(array,vector,deque)의 원소들만 sort()로 정렬할 수 있다.

    vector<int> numbers{99,11,22,3,,66,44,88};
    sort(numbers.begin(),numbers.end());

    // 내림차순으로 정렬하기 위해서는 greater<>()를 세번째 인자로 전달해야한다.
    sort(numbers.begin(),numbers.end(),greater<>());

    // 범위에 있는 원소들을 정렬하면서, 같은 원소들이 원본 순차열과 같은 순서로 남도록 보장하기 위해서는 stable_sort()를 사용해야한다.
    stable_sort(numbers.begin(),numbers.end());

    // 여러개의 원소들 중에서 하위 100개만 관심이 있을 경우 부분정렬함수인 partial_sort()를 사용한다.
    partial_sort(numbers.begin(),numbers.begin()+3,numbers.end());

    vector<int> result(3);
    partial_sort_copy(numbers.begin(),numbers.begin()+3,numbers.end(),greater<>()); // partial_copy_sort()를 사용하면 다른 컨테이넉로 복사하면서 partial_sort()를 시행할 수 있다.

    // 여러개의 원소들 중에서 n번째만 관심이 있을 경우 nth_element()를 사용한다.
    


    return 0;
}