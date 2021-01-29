#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>

using namespace std;

int main(){

    // 수학에서 사용하는 집합이라는 개념과 set 컨테이너의 개념은 매우 닮았다.
    // 두 집합의 내용을 다양한 방식으로 조합해 다른 집합을 만들어낼 수 있다는 두가지 집합 연산이 있다. (합집합,교집합,차집합)
    // algorithm 헤더를 통해서 집합의 연산과 유사한 set연산을 실행할 수 있다.
    // vector에서도 사용할 수 있지만, 대 원칙은 연산이 수행되는 두 집합이 모두 내립차순 or 오름차순으로 정렬되어 있어야 한다.
    // set의 경우에는 greater() or less()가 동일해야한다.

    /* Theme 1 : 합집합 연산 */
    vector<int> set1{1,2,3,4,5,6};
    vector<int> set2{4,5,6,7,8,9};
    vector<int> result;
    set_union(set1.begin(),set1.end(),set2.begin(),set2.end(),back_inserter(result));
    for(int x : result){
        cout << x << ' ';
    }
    cout << '\n';
    set<int,greater<int>>set3{1,2,3,4,5,6};
    set<int,greater<int>>set4{4,5,6,7,8,9};
    set<int,greater<int>>result2;
    set_union(set3.begin(),set3.end(),set4.begin(),set4.end(),inserter(result2,result2.begin()),greater<int>());
    for(int x : result2){
        cout << x << ' ';
    }
    cout << '\n';

    /* Theme 2 : 교집합 연산 */
    set<int> result3;
    set_intersection(set3.begin(),set3.end(),set4.begin(),set4.end(),inserter(result3,result3.begin()),greater<int>());
    for(int x : result3){
        cout << x << ' ';
    }
    cout << '\n';

    /* Theme 3 : 차집합 연산 */
    set<int> result4;
    set_difference(set3.begin(),set3.end(),set4.begin(),set4.end(),inserter(result4,result4.begin()),greater<int>());
    for(int x : result4){
        cout << x << ' ';
    }
    cout << '\n';

    /* Theme 4 : 포함관계확인 */
    if(!includes(set3.begin(),set3.end(),set4.begin(),set4.end())){
        cout << "not including" << '\n';
    }

    return 0;
}