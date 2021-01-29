#include <iostream>
#include <cstring>
#include <array>

using namespace std;

int main(){

    // array<T,N> 템플릿은 표준 배열에 해당하는 컨테이너 타입을 정의한 것이다.
    array<double,100> data; // 원소들은 기본적으로는 초기화 되지 않아서 명시적으로 초기화해주어야 한다.
    array<double,4> values{0.5,1.0,1.5,2.0};
    array<string,5> words{"one","two","three","four","five"};
    array<double, 5> these{1.0,2.0,3.0,4.0,5.0};

    data.fill(3.141592); // fill()을 호출하여서 모든 원소를 특정한 값으로 설정할 수 있다.


    /* Theme1 : 원소에 접근하기 */
    values[3]= values[2] + 2.0*values[1]; // []을 이용하여 특정한 인덱스에 접근할 수 있다.

    values.at(0)= values.at(2) + 2.0*values.at(1); // at()는 사용한 인수가 범위를 벗어난 값인지 확인한다. 이는 성능의 저하를 야기시키지만 안전성을 보장할 수 있게 해준다.

    cout << get<3>(words) << '\n'; // get<> 함수 템플릿을 이용해서 인덱스에 접근할 수 있다. 단, get<i>와 같이 루프 변수를 사용해서는 안된다.

    // for문
    double total=0.0;
    for(int i=0;i<values.size();i++){ // size()를 통해서 컨테이너가 갖고 있는 원소의 전체 개수를 구할 수 있다.
        total += values[i];
    }

    // enhanced for문
    double totalsum=0.0;
    for(auto& value:values){
        totalsum += value;
    }

    if(values.empty()){ // empty()를 통해서 컨테이너가 현재 갖고 있는 원소의 개수가 0개인지 아닌지에 대해서 알 수 있다.
        cout << "container has no elements." << '\n';
    }
    else{
        cout << "container has elements." << '\n'; 
    }


    /* Theme2 : 반복자 사용하기 */
    auto firsti = values.begin(); // 첫번째 원소를 가리키는 반복자를 얻을 수 있다.
    auto secondi = values.end(); // 마지막 원소보다 하나 더 뒤를 가리키는 반복자를 얻을 수 있다.

    double sum=0.0;
    while(firsti != secondi){
        sum += *firsti++;
    }
    sum=0.0;

    auto start = these.rbegin(); // 마지막 원소를 가리키는 반복자를 얻을 수 있다.
    auto finish = these.rend(); // 첫 원소보다 하나 앞을 가리키는 역방향 반복자를 얻을 수 있다.

    while(start != finish){
        sum += *(start++);
    }
    sum= 0.0;

    for(auto iter= these.rbegin();iter!=these.rend();++iter){
        sum += *iter;
    }
    

    /* Theme3 : array 컨테이너의 비교 */
    array<double,4> those{1.0,2.0,3.0,4.0};
    array<double,4> them {1.0,2.0,2.0,4.0};

    if(those==them) cout << "those and them are equal" << '\n'; // array들이 같은 크기이고, 같은 타입이며, 이 타입이 비교 연산을 지원한다면 비교 연산자를 통해서 컨테이너를 비교할 수 있다.
    them = those; // 비교 연산이 되는 것과 같은 조건하에서 대입 연산을 할 수도 있다.


    return 0;
}